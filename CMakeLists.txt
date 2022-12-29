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
        src/actions/HitAction.cpp
        src/actions/MoveAndHealAction.cpp
        src/actions/MoveAndRevealAction.cpp
        src/ship/ArmouredShip.cpp
        src/ship/SupporterShip.cpp include/ship/SupporterShip.h include/ship/Submarine.h src/ship/Submarine.cpp src/commands/Command.cpp include/commands/Command.h src/commands/RemoveRevealedCommand.cpp include/commands/RemoveRevealedCommand.h src/actions/RemoveRevealedAction.cpp include/actions/RemoveRevealedAction.h src/actions/RemoveHitAction.cpp include/actions/RemoveHitAction.h src/actions/RemoveHitMissAction.cpp include/actions/RemoveHitMissAction.h src/commands/RemoveHitCommand.cpp include/commands/RemoveHitCommand.h src/actions/RemoveHitMissCommand.cpp include/commands/RemoveHitMissCommand.h)
