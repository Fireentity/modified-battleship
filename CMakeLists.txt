cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-g -O2")
project(progetto_finale)

include_directories(include)

add_executable(battaglia_navale
        src/battleship.cpp
        src/board/Board.cpp
        src/board/BoardSlot.cpp
        src/ship/Ship.cpp
        src/ship/ShipPiece.cpp
        src/ship/Armoured.cpp
        src/ship/Supporter.cpp
        src/ship/Submarine.cpp
        src/Game.cpp
        src/player/Player.cpp
        src/player/AI.cpp
        src/player/Human.cpp
        src/player/ReplayConsolePlayer.cpp
        src/player/ReplayFilePlayer.cpp
        src/Point.cpp
        src/actions/HitAction.cpp
        src/actions/MoveAndHealAction.cpp
        src/actions/MoveAndRevealAction.cpp
        src/commands/Command.cpp
        src/commands/RemoveRevealedCommand.cpp
        src/commands/RemoveHitCommand.cpp
        src/commands/RemoveMissedCommand.cpp
        src/commands/ShipCommand.cpp
        src/commands/ShipPlaceCommand.cpp
        src/commands/ShipActionCommand.cpp
        src/commands/PrintCommand.cpp
        src/logger/ConsoleLogger.cpp
        src/logger/FileLogger.cpp
        src/Utilities.hpp
        src/RandomNumber.cpp)

add_executable(replay
        src/replay.cpp
        src/board/Board.cpp
        src/board/BoardSlot.cpp
        src/ship/Ship.cpp
        src/ship/ShipPiece.cpp
        src/ship/Armoured.cpp
        src/ship/Supporter.cpp
        src/ship/Submarine.cpp
        src/Game.cpp
        src/player/Player.cpp
        src/player/AI.cpp
        src/player/Human.cpp
        src/player/ReplayConsolePlayer.cpp
        src/player/ReplayFilePlayer.cpp
        src/Point.cpp
        src/actions/HitAction.cpp
        src/actions/MoveAndHealAction.cpp
        src/actions/MoveAndRevealAction.cpp
        src/commands/Command.cpp
        src/commands/RemoveRevealedCommand.cpp
        src/commands/RemoveHitCommand.cpp
        src/commands/RemoveMissedCommand.cpp
        src/commands/ShipCommand.cpp
        src/commands/ShipPlaceCommand.cpp
        src/commands/ShipActionCommand.cpp
        src/commands/PrintCommand.cpp
        src/logger/ConsoleLogger.cpp
        src/logger/FileLogger.cpp
        src/Utilities.hpp
        src/RandomNumber.cpp)


