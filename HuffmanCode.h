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
};

class HuffmanTree {
    using CmpFunc_t    = std::function<bool(const Position_t& x, const Position_t& y)>;
    using CodeMap_t    = std::map<char, String>;
    using CharPosMap_t = std::map<char, Position_t>;

    CmpFunc_t cmpFunc = [](const Position_t& x, const Position_t& y) -> bool {
        return x->data.weight > y->data.weight;
    };
    using CandidateQueue_t = std::priority_queue<Position_t, std::vector<Position_t>, decltype(cmpFunc)>;

    Position_t       head;
    CodeMap_t        codeMap;
    CharPosMap_t     chPosMap;
    CandidateQueue_t candidateQueue;

public:
    HuffmanTree();

    void push(ElemType& data);
    void build();
};
