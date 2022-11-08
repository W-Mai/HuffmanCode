#include "HuffmanCode.h"

HuffmanTree::HuffmanTree()
    : head(nullptr) {
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
}
