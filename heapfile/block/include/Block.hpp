//
// Created by micha on 5. 8. 2026.
//

#ifndef DATABASE_BLOCK_HPP
#define DATABASE_BLOCK_HPP
#include <cstdint>
#include <cstring>
#include <vector>

enum class BlockType : std::uint8_t {
    HEAP_FILE_HEADER,
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

    template<typename T>
    requires std::is_trivially_copyable_v<T>
    static void appendVectorBytes(std::vector<std::byte>& bytes, const std::vector<T>& values) {
        appendBytes(bytes, static_cast<std::uint16_t>(values.size()));

        const std::size_t oldSize = bytes.size();
        const std::size_t dataSize = values.size() * sizeof(T);

        bytes.resize(oldSize + dataSize);

        std::memcpy(bytes.data() + oldSize, values.data(), dataSize);
    }

    virtual void appendData(std::vector<std::byte>& bytes) const = 0;

public:
    Block(std::uint16_t blockSize, BlockType blockType);

    [[nodiscard]] std::uint16_t getBlockSize() const;
    [[nodiscard]] BlockType getBlockType() const;

    [[nodiscard]] std::vector<std::byte> getBytes() const;

    virtual ~Block() = default;
};


#endif //DATABASE_BLOCK_HPP