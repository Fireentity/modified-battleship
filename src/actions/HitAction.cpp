//Lorenzo Croce 2034738

#include "actions/HitAction.h"

HitAction::HitAction(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board)
        : Action{board, enemy_board} {
}

bool HitAction::do_action(const Point &ship_center, const Point &target) {
    if (Board::is_out(ship_center) || Board::is_out(target)) {
        return false;
    }

    if (!board_.lock()->get_slot(ship_center).has_ship()) {
        return false;
    }

    if (!enemy_board_.lock()->get_slot(target).has_ship()) {
        board_.lock()->get_slot(target).set_state(BoardSlot::HIT_MISSED);
        return true;
    }

    if(enemy_board_.lock()->get_slot(target).get_ship()->get_piece(target)->is_hit()) {
        return true;
    }

    board_.lock()->get_slot(target).set_state(BoardSlot::HIT);
    std::shared_ptr<Ship> ship = enemy_board_.lock()->get_slot(target).get_ship();
    ship->hit(target);

    if(ship->get_health() <= 0) {
        enemy_board_.lock()->remove_ship(ship->get_center());
    }

    return true;
}
