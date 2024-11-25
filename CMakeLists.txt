cmake_minimum_required(VERSION 3.10)

project(HuffmanCompressionTool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "D:/qt/6.5.3/mingw_64/lib/cmake")
set(CMAKE_DISABLE_FIND_PACKAGE_Vulkan ON)
set(CMAKE_AUTOMOC ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(HuffmanCompressionTool
    src/HuffmanCoding.cpp
    src/GUI.cpp
    src/main.cpp
)

target_include_directories(HuffmanCompressionTool PUBLIC src/)
target_link_libraries(HuffmanCompressionTool Qt6::Widgets)
