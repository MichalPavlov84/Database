//
// Created by micha on 5. 8. 2026.
//

#ifndef DATABASE_HEAPFILE_HPP
#define DATABASE_HEAPFILE_HPP
#include <concepts>
#include "../block/include/Block.hpp"

template <std::derived_from<Block> BLOCK>
class HeapFile {
    const int blockSize;
public:
    HeapFile(const int blockSize)
        : blockSize(blockSize) { }

    BLOCK readABlockFromFile(int blockId) {

    }

    void writeABlockToFile(BLOCK block) {

    }

    bool freeABlockFromFile(int blockId) {

    }
};


#endif //DATABASE_HEAPFILE_HPP