#include "HuffmanCode.h"
#include <cstdio>

HuffmanTree* huffmanTree;

int main() {
    huffmanTree = new HuffmanTree;

    ElemType freq_table[] = {
        {'H',  1     },
        { 'a', 9     },
        { 'p', 99    },
        { 'P', 11    },
        { 'y', 2     },
        { ' ', 3     },
        { 'B', 19    },
        { 'i', 91    },
        { 'r', 12    },
        { 't', 31    },
        { 'h', 999   },
        { 'd', 112   },
        { 'a', 319   },
        { 'Y', 999112},
        { ' ', 3     },
        { 'T', 199   },
        { 'o', 9112  },
        { ' ', 3     },
        { 'M', 1999  },
        { 'e', 1123  },
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