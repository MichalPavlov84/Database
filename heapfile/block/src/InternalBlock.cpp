//
// Created by micha on 26. 10. 2026.
//

#include "../include/InternalBlock.hpp"

InternalBlock::InternalBlock(const std::uint16_t blockSize)
    : BPlusTreeBlock(blockSize, BlockType::INTERNAL) {
}