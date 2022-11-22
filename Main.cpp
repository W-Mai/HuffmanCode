#include "HuffmanCode.h"
#include <cstdio>

HuffmanTree* huffmanTree;

int main() {
    huffmanTree = new HuffmanTree;

    ElemType freq_table[] = {
        {'a',  10},
        { 'b', 1 },
        { 'c', 20},
        { 'd', 15},
        { 'e', 3 }
    };

    for (auto& freq : freq_table) {
        huffmanTree->push(freq);
    }

    huffmanTree->build();

    for (auto& freq : freq_table) {
        printf("Raw: %c\tPrefixCode: %s\n", freq.ch, huffmanTree->preCode(freq.ch).c_str());
    }

    printf("WPL: %f", huffmanTree->wpl());

    delete huffmanTree;
    return 0;
}