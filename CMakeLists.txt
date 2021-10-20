cmake_minimum_required(VERSION 3.20)
project(pong)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)


add_executable(pong src/main.cpp
                    src/App.cpp
                    src/Console.cpp
)

