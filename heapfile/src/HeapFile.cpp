//
// Created by micha on 29. 8. 2026.
//

#include "../include/HeapFile.hpp"

HeapFile::HeapFile(std::fstream&& file, const std::uint16_t blockSize)
    : file_(std::move(file)), blockSize_(blockSize) { }

std::streamoff HeapFile::getAddressFromBlockId(const std::uint64_t blockId) const {
    return static_cast<std::streamoff>(blockId) * blockSize_;
}


HeapFile HeapFile::create(const std::filesystem::path& filePath, const std::uint16_t blockSize) {
    if (std::filesystem::exists(filePath)) {
        throw std::filesystem::filesystem_error(
            "File already exists",
            filePath,
            std::make_error_code(std::errc::file_exists)
        );
    }
    std::fstream file(filePath, std::ios::in | std::ios::out | std::ios::binary);
    return {std::move(file), blockSize};
}

HeapFile HeapFile::open(const std::filesystem::path& filePath) {
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
    std::fstream file(filePath, std::ios::in | std::ios::out | std::ios::binary);
    //TODO
}

int HeapFile::getBlockSize() const {
    return blockSize_;
}

std::vector<std::byte> HeapFile::readABlockFromFile(std::uint64_t blockId) {

}

void HeapFile::writeABlockToFile(const Block &block) {

}

bool HeapFile::freeABlockFromFile(const std::uint64_t blockId) {
}
