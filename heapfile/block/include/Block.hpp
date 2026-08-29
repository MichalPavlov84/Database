//
// Created by micha on 5. 8. 2026.
//

#ifndef DATABASE_BLOCK_HPP
#define DATABASE_BLOCK_HPP
#include <cstdint>
#include <cstring>
#include <vector>

enum class BlockType : std::uint8_t {
    FREE_IDS_BLOCK,
    INTERNAL,
    LEAF
};

class Block {
    const std::uint16_t blockSize_;
    const BlockType blockType_;

protected:
    template<typename T>
    requires std::is_trivially_copyable_v<T>
    static void appendBytes(std::vector<std::byte>& bytes, const T& value) {
        const std::size_t oldSize = bytes.size();

        bytes.resize(oldSize + sizeof(T));

        std::memcpy(bytes.data() + oldSize, &value, sizeof(T));
    }

    virtual void appendData(std::vector<std::byte>& bytes) = 0;

public:
    Block(std::uint16_t blockSize, BlockType blockType);

    [[nodiscard]] std::uint16_t getBlockSize() const;
    [[nodiscard]] BlockType getBlockType() const;

    [[nodiscard]] std::vector<std::byte> getBytes() const;

    virtual ~Block() = default;
};


#endif //DATABASE_BLOCK_HPP