//
// Created by micha on 8. 8. 2026.
//

#ifndef DATABASE_LEAFBLOCK_HPP
#define DATABASE_LEAFBLOCK_HPP
#include "BPlusTreeBlock.hpp"

template<typename Key>
class LeafBlock : BPlusTreeBlock<Key> {

public:
    LeafBlock(std::uint16_t blockSize, BlockType blockType)
        : BPlusTreeBlock<Key>(blockSize, blockType) {
    }
};


#endif //DATABASE_LEAFBLOCK_HPP