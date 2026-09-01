//
// Created by micha on 5. 8. 2026.
//

#ifndef DATABASE_HEAPFILE_HPP
#define DATABASE_HEAPFILE_HPP
#include <concepts>
#include <filesystem>
#include <ios>
#include <fstream>

#include "../block/include/Block.hpp"

class HeapFile {
    const std::fstream file_;
    const std::uint16_t blockSize_;

    HeapFile(std::fstream&& file, std::uint16_t blockSize);

    [[nodiscard]] std::streamoff getAddressFromBlockId(std::uint64_t blockId) const;

public:

    static HeapFile create(const std::filesystem::path& filePath, std::uint16_t blockSize);
    static HeapFile open(const std::filesystem::path& filePath);

    [[nodiscard]] int getBlockSize() const;

    std::vector<std::byte> readABlockFromFile(std::uint64_t blockId);

    void writeABlockToFile(const Block& block);

    bool freeABlockFromFile(std::uint64_t blockId);
};


#endif //DATABASE_HEAPFILE_HPP