//
// Created by micha on 8. 8. 2026.
//

#ifndef DATABASE_INTERNALBLOCK_HPP
#define DATABASE_INTERNALBLOCK_HPP
#include "BPlusTreeBlock.hpp"

template<typename Key>
class InternalBlock final : public BPlusTreeBlock<Key> {

public:
    explicit InternalBlock(std::uint16_t blockSize)
        : BPlusTreeBlock<Key>(blockSize, BlockType::INTERNAL) {
    }
};


#endif //DATABASE_INTERNALBLOCK_HPP