//
// Created by micha on 8. 8. 2026.
//

#ifndef DATABASE_INTERNALBLOCK_HPP
#define DATABASE_INTERNALBLOCK_HPP
#include "BPlusTreeBlock.hpp"

class InternalBlock final : public BPlusTreeBlock {

public:
    explicit InternalBlock(const std::uint16_t blockSize)
        : BPlusTreeBlock(blockSize, BlockType::INTERNAL) {
    }
};


#endif //DATABASE_INTERNALBLOCK_HPP