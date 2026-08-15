//
// Created by micha on 5. 8. 2026.
//

#ifndef DATABASE_BLOCK_HPP
#define DATABASE_BLOCK_HPP
#include <vector>

enum class BlockType {
    INTERNAL,
    LEAF
};

class Block {
    const BlockType blockType;
    const unsigned short blockSize;

public:
    Block(BlockType blockType, unsigned short blockSize);

    [[nodiscard]] BlockType getBlockType() const;
    [[nodiscard]] unsigned short getBlockSize() const;

    [[nodiscard]] virtual std::vector<std::byte> getBytes() const = 0;

    virtual ~Block() = default;
};


#endif //DATABASE_BLOCK_HPP