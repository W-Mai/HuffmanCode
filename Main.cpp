#include "HuffmanCode.h"
#include <cstdio>

HuffmanTree* huffmanTree;

typedef std::map<uint8_t, ElemType> WordFreq;

WordFreq wordFreq(std::string str);

int main() {
    huffmanTree = new HuffmanTree;

    auto str        = std::string("This is a HuffmanCode example");
    auto freq_table = wordFreq(str);

    for (auto& freq : freq_table) {
        huffmanTree->push(freq.second);
    }

    huffmanTree->build();

    for (auto& freq : freq_table) {
        printf("Raw: %c\tPrefixCode: %s\n", freq.second.ch, huffmanTree->preCode(freq.second.ch).c_str());
    }

    printf("WPL: %f", huffmanTree->wpl());

    delete huffmanTree;
    return 0;
}

WordFreq wordFreq(std::string str) {
    WordFreq freq;
    for (auto& ch : str) {
        freq[ch].ch = ch;
        freq[ch].weight++;
    }
    return freq;
}
