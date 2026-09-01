//
// Created by micha on 15. 8. 2026.
//

#ifndef DATABASE_BPLUSTREEBLOCK_HPP
#define DATABASE_BPLUSTREEBLOCK_HPP
#include "Block.hpp"

class BPlusTreeBlock : public Block {

public:

    BPlusTreeBlock(const std::uint16_t blockSize, const BlockType blockType)
        : Block(blockSize, blockType) {
    }

    [[nodiscard]] virtual bool isFull() const = 0;
    [[nodiscard]] virtual bool isUnderFlow() const = 0;

    ~BPlusTreeBlock() override = default;
};



#endif //DATABASE_BPLUSTREEBLOCK_HPP