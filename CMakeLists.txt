cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(progetto_finale)

include_directories(include)

add_executable(battaglia_navale
        src/battleship.cpp
        src/ship/Ship.cpp
        src/board/Board.cpp
        src/board/BoardSlot.cpp
        src/ship/ShipPiece.cpp
        src/Game.cpp
        src/player/Player.cpp
        src/player/AI.cpp
        src/player/Human.cpp
        src/Point.cpp
        src/actions/HitAction.cpp
        src/actions/MoveAndHealAction.cpp
        src/actions/MoveAndRevealAction.cpp
        src/ship/Armoured.cpp
        src/ship/Supporter.cpp
        src/ship/Submarine.cpp
        src/commands/Command.cpp
        src/commands/RemoveRevealedCommand.cpp
        src/commands/RemoveHitCommand.cpp
        src/commands/RemoveMissedCommand.cpp
        src/commands/ShipCommand.cpp
        src/commands/ShipPlaceCommand.cpp
        src/commands/ShipActionCommand.cpp
        src/player/ReplayPlayer.cpp
        src/commands/PrintCommand.cpp
        src/logger/ConsoleLogger.cpp
        src/logger/FileLogger.cpp
        src/Utilities.hpp)

add_executable(replay
        src/replay.cpp
        src/ship/Ship.cpp
        src/board/Board.cpp
        src/board/BoardSlot.cpp
        src/ship/ShipPiece.cpp
        src/Game.cpp
        src/player/Player.cpp
        src/player/AI.cpp
        src/player/Human.cpp
        src/Point.cpp
        src/actions/HitAction.cpp
        src/actions/MoveAndHealAction.cpp
        src/actions/MoveAndRevealAction.cpp
        src/ship/Armoured.cpp
        src/ship/Supporter.cpp
        src/ship/Submarine.cpp
        src/commands/Command.cpp
        src/logger/ConsoleLogger.cpp
        src/logger/FileLogger.cpp
        src/commands/RemoveRevealedCommand.cpp
        src/commands/RemoveHitCommand.cpp
        src/commands/RemoveMissedCommand.cpp
        src/commands/ShipCommand.cpp
        src/commands/ShipPlaceCommand.cpp
        src/commands/ShipActionCommand.cpp
        src/commands/PrintCommand.cpp
        src/player/ReplayPlayer.cpp)


