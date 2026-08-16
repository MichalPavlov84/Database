//
// Created by micha on 8. 8. 2026.
//

#ifndef DATABASE_INTERNALBLOCK_HPP
#define DATABASE_INTERNALBLOCK_HPP
#include "BPlusTreeBlock.hpp"

template<typename Key>
class InternalBlock : public BPlusTreeBlock<Key> {

public:
    InternalBlock(std::uint16_t blockSize, BlockType blockType)
        : BPlusTreeBlock<Key>(blockSize, blockType) {
    }
};


#endif //DATABASE_INTERNALBLOCK_HPP