//
// Created by micha on 21. 8. 2026.
//

#include "../include/FreeIdsBlock.hpp"

FreeIdsBlock::FreeIdsBlock(const std::uint16_t blockSize)
    : Block(blockSize, BlockType::FREE_IDS_BLOCK){
}

std::vector<std::byte> FreeIdsBlock::getBytes() const {
}

std::uint64_t FreeIdsBlock::getNextFreeBlockId() const {
    return nextFreeBlockId_;
}

std::vector<std::uint64_t> FreeIdsBlock::getFreeBlockIds() const {
    return freeBlockIds_;
}

void FreeIdsBlock::setNextFreeBlockId(const std::uint64_t nextFreeBlockId) {
    nextFreeBlockId_ = nextFreeBlockId;
}

void FreeIdsBlock::setFreeBlockIds(std::vector<std::uint64_t>&& freeBlockIds) {
    freeBlockIds_ = std::move(freeBlockIds);
}
