#include "actions/MoveAndRevealAction.h"

const int MoveAndRevealAction::range = 3;

MoveAndRevealAction::MoveAndRevealAction(const std::shared_ptr<Board> &board_,
                                         const std::shared_ptr<Board> &enemy_board) : Action(board_, enemy_board) {

}

bool MoveAndRevealAction::do_action(const Point &ship_center, const Point &target) {
    if(Board::is_out(ship_center) || Board::is_out(target)) {
        return false;
    }

    std::shared_ptr<Ship> ship = get_slot(ship_center).get_ship();
    bool can_move = move_ship(ship->get_center(),target);
    if(!can_move) {
        return false;
    }


    int center_x = ship->get_center().get_x() - (range / 2);
    int center_y = ship->get_center().get_y() - (range / 2);
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < range; j++) {
            if(!Board::is_out(center_x + j, center_y + i)) {
                BoardSlot &slot = get_enemy_slot(center_x + j, center_y + i);
                if (slot.has_ship()) {
                    get_slot(center_x + j, center_y + i).set_state(BoardSlot::REVEALED);
                }
            }
        }
    }

    return false;
}


