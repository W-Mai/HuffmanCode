/*
 * MIT License
 * Copyright (c) 2022 XCLZ STUDIO@W-Mai
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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

    void   combine(Position_t parent, Position_t left, Position_t right);
    String preCode(Position_t pos);

public:
    HuffmanTree();
    ~HuffmanTree();

    void push(ElemType& data);
    void build();

    double wpl();
    String preCode(uint8_t code);
};
