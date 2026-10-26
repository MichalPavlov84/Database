cmake_minimum_required(VERSION 4.1)
project(Database)

set(CMAKE_CXX_STANDARD 26)

add_executable(Database main.cpp
        heapfile/include/HeapFile.hpp
        heapfile/block/src/Block.cpp
        heapfile/block/include/Block.hpp
        heapfile/block/include/InternalBlock.hpp
        heapfile/block/include/LeafBlock.hpp
        heapfile/block/include/BPlusTreeBlock.hpp
        heapfile/block/src/FreeIdsBlock.cpp
        heapfile/block/include/FreeIdsBlock.hpp
        heapfile/src/HeapFile.cpp
        Types.hpp
        heapfile/block/src/HeapFileHeaderBlock.cpp
        heapfile/block/include/HeapFileHeaderBlock.hpp
        heapfile/block/src/BPlusTreeBlock.cpp
        heapfile/block/src/InternalBlock.cpp
        heapfile/block/src/LeafBlock.cpp
)
