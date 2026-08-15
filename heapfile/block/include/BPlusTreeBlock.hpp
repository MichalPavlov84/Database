//
// Created by micha on 15. 8. 2026.
//

#ifndef DATABASE_BPLUSTREEBLOCK_HPP
#define DATABASE_BPLUSTREEBLOCK_HPP
#include <memory>
#include "Block.hpp"

template<typename Key>
class BPlusTreeBlock : public Block {

public:

    struct SplitResult {
        std::unique_ptr<BPlusTreeBlock> rightBlock;
        Key separator;
    };

    BPlusTreeBlock(const BlockType blockType, const unsigned short blockSize)
        : Block(blockType, blockSize) {
    }

    [[nodiscard]] virtual SplitResult split() = 0;
    [[nodiscard]] virtual bool isFull() const = 0;
    [[nodiscard]] virtual bool isUnderFlow() const = 0;

    ~BPlusTreeBlock() override = default;
};



#endif //DATABASE_BPLUSTREEBLOCK_HPP