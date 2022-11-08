#pragma once

#include <map>
#include <queue>
#include <string>

using String = std::string;

struct BiTreeNode;

struct ElemType {
    uint8_t  ch;
    uint32_t weight;
};

using Position_t = BiTreeNode*;

struct BiTreeNode {
    ElemType   data;
    Position_t parent, left, right;

    bool operator()(const Position_t& x, const Position_t& y) const {
        return x->data.weight > y->data.weight;
    }
};

class HuffmanTree {
    using CodeMap_t           = std::map<uint8_t, String>;
    using CharPosMap_t        = std::map<uint8_t, Position_t>;
    const uint8_t PARENT_CHAR = -1;

    using CandidateQueue_t = std::priority_queue<Position_t, std::vector<Position_t>, BiTreeNode>;

    Position_t       head;
    CodeMap_t        codeMap;
    CharPosMap_t     chPosMap;
    CandidateQueue_t candidateQueue;

    void combine(Position_t parent, Position_t left, Position_t right);

public:
    HuffmanTree();

    void push(ElemType& data);
    void build();
};
