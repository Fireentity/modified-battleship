cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
project(progetto_finale)

include_directories(include)
include_directories(src)

#Crea un eseguibile main in /build/main
#Linka la libreria date e isbn all'eseguibile main
add_executable(battaglia_navale src/battleship.cpp
        src/ship/Ship.cpp
        src/board/BoardPiece.cpp
        src/ship/Supporter.hpp
        src/ship/Submarine.hpp
        src/ship/ArmouredShip.cpp
        src/Logger.cpp
        src/Game.cpp
        src/AI.cpp
        src/board/DefenceBoard.cpp
        src/board/AttackBoard.cpp src/ship/Submarine.cpp include/ship/Submarine.h)

#Crea un eseguibile main in /build/main
#Linka la libreria date e isbn all'eseguibile main
add_executable(replay src/replay.cpp)
