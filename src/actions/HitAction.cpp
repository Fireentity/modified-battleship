#include "actions/HitAction.h"

bool HitAction::do_action(const Point &ship_center, const Point &target) {
    if (Board::is_out(ship_center) || Board::is_out(target)) {
        return false;
    }

    if (!get_slot(ship_center).has_ship()) {
        return false;
    }
    if (get_enemy_slot(target).has_ship() && get_enemy_slot(target).get_state() !=
                                             BoardSlot::HIT) { //TODO se la nave è gia stata colpita in quel punto non deve succedere (fatto?)
        get_slot(target).set_state(BoardSlot::HIT);
        std::shared_ptr<Ship> ship = get_enemy_slot(target).get_ship();
        ship->set_health(ship->get_health() - 1);
    } else {
        get_slot(target).set_state(BoardSlot::HIT_MISSED);
    }
    return true;
}

HitAction::HitAction(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board)
        : Action{board, enemy_board} {
}
