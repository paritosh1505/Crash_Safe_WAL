cmake_minimum_required(VERSION 3.16)
project(CrashSafeWAL)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)

add_executable(crash_safe_wal src/file.cpp src/main.cpp)

target_include_directories(crash_safe_wal PRIVATE src)

target_compile_options(crash_safe_wal PRIVATE
        -Wall
        -Werror
        -Wextra
        -Wconversion
        -pedantic

)

target_link_options(crash_safe_wal PRIVATE
        -fsanitize=address,undefined
)