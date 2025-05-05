cmake_minimum_required(VERSION 3.14)
project(crow_project)

set(CMAKE_CXX_STANDARD 17)

# Đường dẫn tới thư viện Crow (giả sử bạn đã clone về external/crow)
set(CROW_DIR "${CMAKE_SOURCE_DIR}/external/crow")

# Thêm include path cho tất cả thư mục con của Main/
include_directories(
    ${CROW_DIR}/include
    ${CMAKE_SOURCE_DIR}/Main
    ${CMAKE_SOURCE_DIR}/Main/models
    ${CMAKE_SOURCE_DIR}/Main/routes
)

# Bao gồm tất cả các file .cpp từ thư mục Main và các thư mục con
file(GLOB_RECURSE MAIN_SOURCES "Main/*.cpp" "Main/models/*.cpp" "Main/routes/*.cpp")
add_executable(server Main/main.cpp ${MAIN_SOURCES})


# Link với pthread (bắt buộc cho Crow)
target_link_libraries(server pthread)
