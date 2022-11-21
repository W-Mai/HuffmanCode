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

    for (int i = 0; i < 10; ++i) {
        std::cout << huffmanTree->preCode(i) << std::endl;
    }

    std::cout << huffmanTree->wpl() << std::endl;

    delete huffmanTree;
    return 0;
}