#include "actions/MoveAndHealAction.h"

const int MoveAndHealAction::range = 2;

MoveAndHealAction::MoveAndHealAction(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board)
        : Action(board_, enemy_board) {

}

bool MoveAndHealAction::do_action(const Point &ship_center, const Point &target) {
    if(Board::is_out(ship_center) || Board::is_out(target)) {
        return false;
    }

    std::shared_ptr<Ship> ship = get_slot(ship_center).get_ship();
    bool can_move = move_ship(ship->get_center(),target);
    if(!can_move) {
        return false;
    }

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < range; j++) {
            if(!Board::is_out(target.get_x() + j, target.get_y() + i)) {
                BoardSlot &slot = get_slot(target.get_x() + j, target.get_y() + i);
                if (slot.has_ship() && (slot.get_ship() != get_slot(target).get_ship())) {
                    slot.get_ship()->heal();
                }
            }
        }
    }

    return true;
}
