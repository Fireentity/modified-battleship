cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(progetto_finale)

include_directories(include)

add_executable(battaglia-navale
        src/ship/Ship.cpp
        src/battleship.cpp
        src/board/Board.cpp
        src/board/BoardSlot.cpp
        src/ship/ShipPiece.cpp
        src/Game.cpp
        src/player/Player.cpp
        src/player/AI.cpp
        src/player/Human.cpp
        src/Point.cpp
        src/action/HitAction.cpp
        src/action/MoveAndHealAction.cpp
        src/action/MoveAndRevealAction.cpp)
