
#include "board/DefenceBoard.h"

DefenceBoard::DefenceBoard(const std::vector <std::shared_ptr<Ship>> &ships) {
    for(const std::shared_ptr<Ship> &ship : ships) {
        ship->place(this);
    }
}
