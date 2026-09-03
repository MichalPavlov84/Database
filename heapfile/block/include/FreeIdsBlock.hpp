//
// Created by micha on 21. 8. 2026.
//

#ifndef DATABASE_FREEADDRESSESBLOCK_HPP
#define DATABASE_FREEADDRESSESBLOCK_HPP
#include <limits>

#include "Block.hpp"
#include "../../../Types.hpp"

class FreeIdsBlock final : public Block {
    const std::vector<BlockId> freeBlockIds_;
    const BlockId nextFreeBlockId_;

protected:
    void appendData(std::vector<std::byte> &bytes) const override;

public:
    static constexpr BlockId INVALID_BLOCK_ID = std::numeric_limits<BlockId>::max();

    FreeIdsBlock(
        std::uint16_t blockSize,
        const std::vector<BlockId>& freeBlockIds,
        BlockId nextFreeBlockId
        );

    [[nodiscard]] BlockId getNextFreeBlockId() const;
    [[nodiscard]] std::vector<BlockId> getFreeBlockIds() const;

    ~FreeIdsBlock() override = default;
};


#endif //DATABASE_FREEADDRESSESBLOCK_HPP