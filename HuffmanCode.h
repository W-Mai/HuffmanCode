#pragma once

#include <map>
#include <queue>
#include <string>

struct BiTreeNode;

struct ElemType {
    char ch;
    int  weight;
};

typedef BiTreeNode* Position;

struct BiTreeNode {
    ElemType data;
    Position parent, left, right;
};

struct CompareFunc {
    bool operator()(const Position& x, const Position& y) {
        return x->data.weight > y->data.weight;
    }
};

class HuffmanTree {
    Position                    head;
    std::map<char, std::string> codeMap;
    std::map<char, Position>    chPosMap;
    std::priority_queue<Position, std::vector<Position>, CompareFunc>
        candidateQueue;

public:
    HuffmanTree();

    void push(ElemType& data);
    void build();
};
