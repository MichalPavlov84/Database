//
// Created by micha on 21. 8. 2026.
//

#include "../include/FreeAddressesBlock.hpp"

FreeAddressesBlock::FreeAddressesBlock(const std::uint16_t blockSize)
    : Block(blockSize, BlockType::FREE_ADDRESSES_BLOCK){
}

std::vector<std::byte> FreeAddressesBlock::getBytes() const {
}

std::uint64_t FreeAddressesBlock::getNextFreeBlockId() const {
    return nextFreeBlockId_;
}

std::vector<std::uint64_t> FreeAddressesBlock::getFreeBlockIds() const {
    return freeBlockIds_;
}

void FreeAddressesBlock::setNextFreeBlockId(const std::uint64_t nextFreeBlockId) {
    nextFreeBlockId_ = nextFreeBlockId;
}

void FreeAddressesBlock::setFreeBlockIds(std::vector<std::uint64_t>&& freeBlockIds) {
    freeBlockIds_ = std::move(freeBlockIds);
}
