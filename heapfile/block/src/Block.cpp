//
// Created by micha on 5. 8. 2026.
//

#include "../include/Block.hpp"

Block::Block(const std::uint16_t blockSize, const BlockType blockType)
    : blockSize(blockSize), blockType(blockType) {
}

std::uint16_t Block::getBlockSize() const {
    return blockSize;
}

BlockType Block::getBlockType() const {
    return blockType;
}