//
// Created by micha on 21. 8. 2026.
//

#ifndef DATABASE_FREEADDRESSESBLOCK_HPP
#define DATABASE_FREEADDRESSESBLOCK_HPP
#include <limits>

#include "Block.hpp"


class FreeIdsBlock final : public Block {
    const std::vector<std::uint64_t> freeBlockIds_;
    const std::uint64_t nextFreeBlockId_;

protected:
    void appendData(std::vector<std::byte> &bytes) const override;

public:
    static constexpr std::uint64_t INVALID_BLOCK_ID = std::numeric_limits<std::uint64_t>::max();

    FreeIdsBlock(
        std::uint16_t blockSize,
        const std::vector<std::uint64_t>& freeBlockIds,
        std::uint64_t nextFreeBlockId
        );

    [[nodiscard]] std::uint64_t getNextFreeBlockId() const;
    [[nodiscard]] std::vector<std::uint64_t> getFreeBlockIds() const;

    ~FreeIdsBlock() override = default;
};


#endif //DATABASE_FREEADDRESSESBLOCK_HPP