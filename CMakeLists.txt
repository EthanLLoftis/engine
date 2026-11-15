cmake_minimum_required(VERSION 3.15)
project(engine CXX)



add_executable(engine src/engine.cpp src/main.cpp)



install(TARGETS engine DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
