//
// Created by micha on 26. 10. 2026.
//

#include "../include/BPlusTreeBlock.hpp"

BPlusTreeBlock::BPlusTreeBlock(const std::uint16_t blockSize, const BlockType blockType)
    : Block(blockSize, blockType) {
}