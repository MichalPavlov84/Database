//
// Created by micha on 5. 8. 2026.
//

#include "../include/Block.hpp"

Block::Block(const BlockType blockType, const unsigned short blockSize)
    : blockType(blockType), blockSize(blockSize) {
}

BlockType Block::getBlockType() const {
    return blockType;
}

unsigned short Block::getBlockSize() const {
    return blockSize;
}
