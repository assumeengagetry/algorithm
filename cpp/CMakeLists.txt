cmake_minimum_required(VERSION 3.20)
project(LoggerProject LANGUAGES CXX)

# 指定 C++ 标准（强制要求 C++20）
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 指定编译器（可选，确保使用 g++-11）
set(CMAKE_CXX_COMPILER g++)

# 收集源文件
file(GLOB SOURCES "*.cpp")

# 生成可执行文件
add_executable(logger_app ${SOURCES})

# 链接依赖库（如线程库）
target_link_libraries(logger_app PRIVATE pthread)

# 启用调试信息
set(CMAKE_BUILD_TYPE Debug)
