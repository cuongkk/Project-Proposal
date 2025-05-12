cmake_minimum_required(VERSION 3.14)
project(crow_project)

set(CMAKE_CXX_STANDARD 17)

# Đường dẫn tới thư viện Crow
set(CROW_DIR "${CMAKE_SOURCE_DIR}/external/crow")

# Thêm include path cho thư viện và mã nguồn
include_directories(
    ${CROW_DIR}/include
    ${CMAKE_SOURCE_DIR}/backend/models
    ${CMAKE_SOURCE_DIR}/backend/routes
    ${PROJECT_SOURCE_DIR}/external/asio/asio-1.34.2/include
)

# Bao gồm tất cả các file .cpp từ backend
file(GLOB_RECURSE MAIN_SOURCES 
    "${CMAKE_SOURCE_DIR}/backend/models/*.cpp" 
    "${CMAKE_SOURCE_DIR}/backend/routes/*.cpp"
)

# Tạo executable
add_executable(server ${CMAKE_SOURCE_DIR}/backend/routes/main.cpp ${MAIN_SOURCES})

# Link thư viện cần thiết (chỉ ws2_32 nếu dùng Asio standalone)
target_link_libraries(server ws2_32 mswsock)
