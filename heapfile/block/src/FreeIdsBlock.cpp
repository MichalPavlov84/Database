//
// Created by micha on 21. 8. 2026.
//

#include "../include/FreeIdsBlock.hpp"

FreeIdsBlock::FreeIdsBlock(
    const std::uint16_t blockSize,
    const std::vector<BlockId>& freeBlockIds,
    const BlockId nextFreeBlockId
    )
    : Block(blockSize, BlockType::FREE_IDS),
    freeBlockIds_(freeBlockIds),
    nextFreeBlockId_(nextFreeBlockId) {
}

void FreeIdsBlock::appendData(std::vector<std::byte> &bytes) const {
    appendVectorBytes(bytes, freeBlockIds_);
    appendBytes(bytes, nextFreeBlockId_);
}

BlockId FreeIdsBlock::getNextFreeBlockId() const {
    return nextFreeBlockId_;
}

std::vector<BlockId> FreeIdsBlock::getFreeBlockIds() const {
    return freeBlockIds_;
}
