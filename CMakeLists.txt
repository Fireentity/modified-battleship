cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(progetto_finale)

include_directories(include)

add_executable(battaglia-navale
        src/battleship.cpp
        src/board/AttackBoard.cpp
        src/board/DefenceBoard.cpp
        src/board/BoardSlot.cpp
        src/board/Board.hpp
        src/ship/ArmouredShip.cpp
        src/ship/Submarine.cpp
        src/ship/Supporter.cpp
        src/ship/LinearShip.cpp
        src/ship/Ship.cpp
        src/ship/ShipPiece.cpp
        src/AI.cpp include/Player.h src/Player.cpp)
