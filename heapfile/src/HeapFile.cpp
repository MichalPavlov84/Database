//
// Created by micha on 29. 8. 2026.
//

#include "../include/HeapFile.hpp"

HeapFile::HeapFile(std::fstream&& file, const std::uint64_t blockCount, const std::uint16_t blockSize)
    : file_(std::move(file)), blockCount_(blockCount), blockSize_(blockSize) { }

std::streamoff HeapFile::getAddressFromBlockId(const BlockId blockId) const {
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
    std::fstream file;
    file.exceptions(std::ios::failbit | std::ios::badbit);

    file.open(
        filePath,
        std::ios::in |
        std::ios::out |
        std::ios::binary |
        std::ios::trunc
    );

    const std::vector emptyBlock(blockSize, std::byte{0});
    file.seekp(0, std::ios::beg);
    file.write(
        reinterpret_cast<const std::ostream::char_type *>(emptyBlock.data()),
        static_cast<std::streamsize>(emptyBlock.size())
    );

    return {std::move(file), 1, blockSize};
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

    std::fstream file;
    file.exceptions(std::ios::failbit | std::ios::badbit);

    file.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
    //TODO
}

void HeapFile::close() {
    if (!file_.is_open()) {
        return;
    }
    //TODO
    file_.flush();
    file_.close();
}


int HeapFile::getBlockSize() const {
    return blockSize_;
}

BlockId HeapFile::allocateBlock() {
    if (!freeBlockIds_.empty()) {
        const BlockId blockId = *freeBlockIds_.begin();
        freeBlockIds_.erase(blockId);
        return blockId;
    }
    //TODO
    ++blockCount_;
}

std::vector<std::byte> HeapFile::readBlock(BlockId blockId) {

}

void HeapFile::writeBlock(const BlockId blockId,  const Block& block) {
    if (blockId == 0) {
        throw std::invalid_argument("Block ID 0 is reserved for the header");
    }
    if (blockId >= blockCount_) {
        throw std::out_of_range("Block ID is outside the file");
    }

}

void HeapFile::freeBlock(const BlockId blockId) {
}
