//
// Created by micha on 26. 10. 2026.
//

#include "../include/LeafBlock.hpp"

LeafBlock::LeafBlock(const std::uint16_t blockSize)
    : BPlusTreeBlock(blockSize, BlockType::LEAF) {
}