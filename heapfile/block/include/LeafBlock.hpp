//
// Created by micha on 8. 8. 2026.
//

#ifndef DATABASE_LEAFBLOCK_HPP
#define DATABASE_LEAFBLOCK_HPP
#include "BPlusTreeBlock.hpp"

template<typename Key>
class LeafBlock : BPlusTreeBlock<Key> {

public:
    LeafBlock(BlockType blockType, unsigned short blockSize)
        : BPlusTreeBlock<Key>(blockType, blockSize) {
    }
};


#endif //DATABASE_LEAFBLOCK_HPP