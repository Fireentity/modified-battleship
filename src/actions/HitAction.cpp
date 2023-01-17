#include "actions/HitAction.h"

HitAction::HitAction(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board)
        : Action{board, enemy_board} {
}

bool HitAction::do_action(const Point &ship_center, const Point &target) {
    if (Board::is_out(ship_center) || Board::is_out(target)) {
        return false;
    }

    if (!get_slot(ship_center).has_ship()) {
        return false;
    }

    if (!get_enemy_slot(target).has_ship()) {
        get_slot(target).set_state(BoardSlot::HIT_MISSED);
        return true;
    }

    if(get_enemy_slot(target).get_ship()->get_piece(target)->is_hit()) {
        return true;
    }

    get_slot(target).set_state(BoardSlot::HIT);
    std::shared_ptr<Ship> ship = get_enemy_slot(target).get_ship();
    ship->hit(target);

    if(ship->get_health() <= 0) {
        remove_ship(ship->get_center());
    }

    return true;
}
