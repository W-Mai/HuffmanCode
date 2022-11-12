#include "HuffmanCode.h"
#include <iostream>

HuffmanTree* huffmanTree;

int main() {
    huffmanTree = new HuffmanTree;

    for (int i = 0; i < 10; ++i) {
        huffmanTree->push(*new ElemType {
            .ch     = (uint8_t)i,
            .weight = static_cast<uint32_t>(i),
        });
    }

    huffmanTree->build();

    delete huffmanTree;
    return 0;
}