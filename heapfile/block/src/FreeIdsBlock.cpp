//
// Created by micha on 21. 8. 2026.
//

#include "../include/FreeIdsBlock.hpp"

FreeIdsBlock::FreeIdsBlock(
    const std::uint16_t blockSize,
    const std::vector<std::uint64_t>& freeBlockIds,
    const std::uint64_t nextFreeBlockId
    )
    : Block(blockSize, BlockType::FREE_IDS_BLOCK),
    freeBlockIds_(freeBlockIds),
    nextFreeBlockId_(nextFreeBlockId) {
}

void FreeIdsBlock::appendData(std::vector<std::byte> &bytes) const {
    appendVectorBytes(bytes, freeBlockIds_);
    appendBytes(bytes, nextFreeBlockId_);
}

std::uint64_t FreeIdsBlock::getNextFreeBlockId() const {
    return nextFreeBlockId_;
}

std::vector<std::uint64_t> FreeIdsBlock::getFreeBlockIds() const {
    return freeBlockIds_;
}
