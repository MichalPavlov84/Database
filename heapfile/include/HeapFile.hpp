//
// Created by micha on 5. 8. 2026.
//

#ifndef DATABASE_HEAPFILE_HPP
#define DATABASE_HEAPFILE_HPP

#include <filesystem>
#include <ios>
#include <fstream>
#include <set>

#include "../../Types.hpp"
#include "../block/include/Block.hpp"

class HeapFile {
    std::fstream file_;
    std::set<BlockId> freeBlockIds_;
    std::uint64_t blockCount_;
    const std::uint16_t blockSize_;

    HeapFile(std::fstream&& file, std::uint64_t blockCount, std::uint16_t blockSize);

    [[nodiscard]] std::streamoff getAddressFromBlockId(BlockId blockId) const;

    static void writeBlockBytesAtId(std::fstream& file, std::streamoff address, const std::vector<std::byte>& bytes);
public:

    static HeapFile create(const std::filesystem::path& filePath, std::uint16_t blockSize);
    static HeapFile open(const std::filesystem::path& filePath);
    void close();

    [[nodiscard]] int getBlockSize() const;

    BlockId allocateBlock() const;
    std::vector<std::byte> readBlock(BlockId blockId);
    void writeBlock(BlockId blockId, const Block& block);
    void freeBlock(BlockId blockId);
};


#endif //DATABASE_HEAPFILE_HPP