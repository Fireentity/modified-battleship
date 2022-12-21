cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
project(progetto_finale)

include_directories(include)

#Crea un eseguibile main in /build/main
#Linka la libreria date e isbn all'eseguibile main
add_executable(battaglia_navale src/battleship.cpp
        src/board/AttackBoard.cpp
        src/board/DefenceBoard.cpp
        src/ship/ArmouredShip.cpp
        src/ship/Ship.cpp
        src/ship/BoardPiece.cpp
        src/ship/Submarine.cpp
        src/ship/Supporter.cpp
        src/Logger.cpp
        src/Game.cpp
        src/AI.cpp)

#Crea un eseguibile main in /build/main
#Linka la libreria date e isbn all'eseguibile main
add_executable(replay src/replay.cpp)
