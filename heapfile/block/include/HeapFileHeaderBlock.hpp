//
// Created by micha on 13. 10. 2026.
//

#ifndef DATABASE_HEAPFILEHEADERBLOCK_HPP
#define DATABASE_HEAPFILEHEADERBLOCK_HPP
#include "Block.hpp"


class HeapFileHeaderBlock : public Block {

public:
    HeapFileHeaderBlock(std::uint16_t blockSize, BlockType blockType);
};


#endif //DATABASE_HEAPFILEHEADERBLOCK_HPP