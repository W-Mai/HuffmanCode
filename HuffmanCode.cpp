#include "HuffmanCode.h"

HuffmanTree::HuffmanTree()
    : head(nullptr) {
}

HuffmanTree::~HuffmanTree() {
    std::for_each(chPosMap.begin(), chPosMap.end(), [](auto pos) {
        delete pos.second;
    });
    chPosMap.clear();
}

void HuffmanTree::combine(Position_t parent, Position_t left, Position_t right) {
    parent->parent = nullptr;
    parent->data   = {
          .ch     = PARENT_CHAR,
          .weight = left->data.weight + right->data.weight
    };
    parent->left  = left;
    parent->right = right;
    left->parent  = parent;
    right->parent = parent;
}

void HuffmanTree::push(ElemType& data) {
    auto node = new BiTreeNode {
        .data   = data,
        .parent = nullptr,
        .left   = nullptr,
        .right  = nullptr
    };

    candidateQueue.push(node);
    chPosMap[data.ch] = node;
}

void HuffmanTree::build() {
    if (candidateQueue.empty()) return;

    Position_t parent;
    Position_t left, right;

    auto pop = [](CandidateQueue_t& queue) {
        auto top = queue.top();
        queue.pop();
        return top;
    };

    auto push = [this](Position_t data) {
        this->candidateQueue.push(data);
    };

    while (!candidateQueue.empty()) {
        if (candidateQueue.size() == 1) {
            head = pop(candidateQueue);
            break;
        }
        left   = pop(candidateQueue);
        right  = pop(candidateQueue);
        parent = new BiTreeNode;
        combine(parent, left, right);
        push(parent);
    }

    for (auto& x : chPosMap) {
        codeMap[x.first] = preCode(x.second); // 建立字符到前缀码的哈希映射
    }
}

String HuffmanTree::preCode(Position_t pos) {
    String     code;
    Position_t currentPos = pos;
    while (currentPos->parent) {
        if (currentPos->parent->left == currentPos) {
            code += '0';
        } else code += '1';
        currentPos = currentPos->parent;
    }
    return { code.rbegin(), code.rend() };
}

inline String HuffmanTree::preCode(uint8_t code) {
    return codeMap[code];
}

double HuffmanTree::wpl() {
    double   sum       = 0.0;
    uint32_t weightSum = 0;

    std::for_each(chPosMap.begin(), chPosMap.end(), [&weightSum, &sum, this](const auto& pos) {
        sum += (int)preCode(pos.first).length() * pos.second->data.weight;
        weightSum += pos.second->data.weight;
    });

    return sum / weightSum;
}
