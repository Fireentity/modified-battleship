#include "board/DefenceBoard.h"

const std::regex DefenceBoard::inputCharacterRegex = std::regex{R"([A-Z])"};

DefenceBoard::DefenceBoard() : Board{BoardSlot{}} {
}
