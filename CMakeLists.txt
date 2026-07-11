cmake_minimum_required(VERSION 3.10)
project(superpeople)
set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)
add_executable(people 
    src/main.cpp 
    src/entities.cpp
    src/game.cpp
)
target_include_directories(people
    PRIVATE ${RAYLIB_INCLUDE_DIRS}
    PRIVATE include


)

target_link_libraries( people
    ${RAYLIB_LIBRARIES}

)
