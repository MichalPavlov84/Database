//
// Created by micha on 5. 8. 2026.
//

#include "../include/Block.hpp"

Block::Block(const std::uint16_t blockSize, const BlockType blockType)
    : blockSize_(blockSize), blockType_(blockType) {
}

std::vector<std::byte> Block::getBytes() const {
    std::vector<std::byte> bytes;
    bytes.reserve(blockSize_);

    appendBytes(bytes, blockType_);
    appendData(bytes);

    return bytes;
}

std::uint16_t Block::getBlockSize() const {
    return blockSize_;
}

BlockType Block::getBlockType() const {
    return blockType_;
}