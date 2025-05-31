cmake_minimum_required(VERSION 3.14)
project(crow_project)

set(CMAKE_CXX_STANDARD 17)

# Đường dẫn tới thư viện Crow
set(CROW_DIR "${CMAKE_SOURCE_DIR}/external/crow")

# MySQL Connector path (MSVC version)
set(MYSQL_CONN_ROOT "C:/Users/84328/Downloads/mysql-connector-c++-9.3.0-winx64/mysql-connector-c++-9.3.0-winx64")

# Thêm include path
include_directories(
    ${CROW_DIR}/include
    ${CMAKE_SOURCE_DIR}/backend/images
    ${CMAKE_SOURCE_DIR}/backend/models
    ${CMAKE_SOURCE_DIR}/backend/routes
    ${CMAKE_SOURCE_DIR}/backend/repository
    ${PROJECT_SOURCE_DIR}/external/asio/asio-1.34.2/include
    ${MYSQL_CONN_ROOT}/include
    ${MYSQL_CONN_ROOT}/include/jdbc
    ${PROJECT_SOURCE_DIR}/include
)

# Lấy tất cả file cpp
file(GLOB_RECURSE MAIN_SOURCES 
    "${CMAKE_SOURCE_DIR}/backend/models/*.cpp" 
    "${CMAKE_SOURCE_DIR}/backend/routes/*.cpp"
    "${CMAKE_SOURCE_DIR}/backend/repository/*.cpp"
)

# Tạo executable
add_executable(server ${CMAKE_SOURCE_DIR}/backend/main.cpp ${MAIN_SOURCES})

# Link thư viện cần thiết (nếu dùng asio)
target_link_libraries(server ws2_32 mswsock)

# Link thư viện MySQL Connector C++ cho MSVC
target_link_directories(server PRIVATE ${MYSQL_CONN_ROOT}/lib64/vs14)
target_link_libraries(server mysqlcppconn)
