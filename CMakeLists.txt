cmake_minimum_required(VERSION 3.15)
project(engine CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(engine)

target_sources(engine PRIVATE src/main.cpp)

add_library(enginelib)
target_sources(enginelib 
    PRIVATE
        src/engine.cpp
        src/character.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/engine.h
            include/character.h
)

find_package(SFML REQUIRED)

if(APPLE)
    target_link_options(engine PRIVATE "-ObjC")
    target_link_options(enginelib PRIVATE "-ObjC")
endif()

target_link_libraries(engine PRIVATE enginelib sfml::sfml)
target_link_libraries(enginelib PRIVATE sfml::sfml)


install(TARGETS engine DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
