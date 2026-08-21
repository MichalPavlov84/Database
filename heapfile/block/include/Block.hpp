//
// Created by micha on 5. 8. 2026.
//

#ifndef DATABASE_BLOCK_HPP
#define DATABASE_BLOCK_HPP
#include <cstdint>
#include <vector>

enum class BlockType : std::uint8_t {
    FREE_IDS_BLOCK,
    INTERNAL,
    LEAF
};

class Block {
    const std::uint16_t blockSize_;
    const BlockType blockType_;

public:
    Block(std::uint16_t blockSize, BlockType blockType);

    [[nodiscard]] std::uint16_t getBlockSize() const;
    [[nodiscard]] BlockType getBlockType() const;

    [[nodiscard]] virtual std::vector<std::byte> getBytes() const = 0;

    virtual ~Block() = default;
};


#endif //DATABASE_BLOCK_HPP