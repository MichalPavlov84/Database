//
// Created by micha on 8. 8. 2026.
//

#ifndef DATABASE_INTERNALBLOCK_HPP
#define DATABASE_INTERNALBLOCK_HPP
#include "BPlusTreeBlock.hpp"

template<typename Key>
class InternalBlock : public BPlusTreeBlock<Key> {

public:
    InternalBlock(BlockType blockType, unsigned short blockSize)
        : BPlusTreeBlock<Key>(blockType, blockSize) {
    }
};


#endif //DATABASE_INTERNALBLOCK_HPP