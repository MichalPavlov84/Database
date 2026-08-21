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

template <std::derived_from<Block> BLOCK>
class HeapFile {
    const std::fstream file;
    const std::uint16_t blockSize;

    HeapFile(std::fstream&& file, const std::uint16_t blockSize)
        : file(std::move(file)), blockSize(blockSize) { }

    [[nodiscard]] std::streamoff getAddressFromBlockId(const std::uint64_t blockId) const {
        return static_cast<std::streamoff>(blockId) * blockSize;
    }

public:

    static HeapFile create(const std::filesystem::path& filePath, const std::uint16_t blockSize) {
        if (std::filesystem::exists(filePath)) {
            throw std::filesystem::filesystem_error(
                "File already exists",
                filePath,
                std::make_error_code(std::errc::file_exists)
            );
        }
        //TODO
        //return HeapFile(blockSize);
    }

    static HeapFile open(const std::filesystem::path& filePath) {
        if (!std::filesystem::exists(filePath)) {
            throw std::filesystem::filesystem_error(
                "File doesn't exists",
                filePath,
                std::make_error_code(std::errc::no_such_file_or_directory)
            );
        }

        if (!std::filesystem::is_regular_file(filePath)) {
            throw std::filesystem::filesystem_error(
                "Path is not a regular file",
                filePath,
                std::make_error_code(std::errc::invalid_argument)
            );
        }
        //TODO
        //return HeapFile(blockSize);
    }

    [[nodiscard]] int getBlockSize() const {
        return blockSize;
    }

    BLOCK readABlockFromFile(const std::uint64_t blockId) {

    }

    void writeABlockToFile(const BLOCK& block) {

    }

    bool freeABlockFromFile(const std::uint64_t blockId) {

    }
};


#endif //DATABASE_HEAPFILE_HPP