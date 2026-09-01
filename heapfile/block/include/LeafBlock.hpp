//
// Created by micha on 8. 8. 2026.
//

#ifndef DATABASE_LEAFBLOCK_HPP
#define DATABASE_LEAFBLOCK_HPP
#include "BPlusTreeBlock.hpp"

class LeafBlock final : BPlusTreeBlock {

public:
    explicit LeafBlock(std::uint16_t blockSize)
        : BPlusTreeBlock(blockSize, BlockType::LEAF) {
    }
};


#endif //DATABASE_LEAFBLOCK_HPP