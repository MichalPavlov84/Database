//
// Created by micha on 21. 8. 2026.
//

#ifndef DATABASE_FREEADDRESSESBLOCK_HPP
#define DATABASE_FREEADDRESSESBLOCK_HPP
#include <limits>

#include "Block.hpp"


class FreeIdsBlock final : public Block {
    std::uint64_t nextFreeBlockId_;
    std::vector<std::uint64_t> freeBlockIds_;

public:
    static constexpr std::uint64_t INVALID_BLOCK_ID = std::numeric_limits<std::uint64_t>::max();

    explicit FreeIdsBlock(std::uint16_t blockSize);

    [[nodiscard]] std::vector<std::byte> getBytes() const override;

    [[nodiscard]] std::uint64_t getNextFreeBlockId() const;
    [[nodiscard]] std::vector<std::uint64_t> getFreeBlockIds() const;

    void setNextFreeBlockId(std::uint64_t nextFreeBlockId);
    void setFreeBlockIds(std::vector<std::uint64_t>&& freeBlockIds);

    ~FreeIdsBlock() override = default;
};


#endif //DATABASE_FREEADDRESSESBLOCK_HPP