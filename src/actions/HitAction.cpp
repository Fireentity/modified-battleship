#include "actions/HitAction.h"

bool HitAction::do_action(const Point &target) {
    if(!get_slot(target).has_ship()) {
        BoardSlot &slot = get_enemy_slot(target);
        slot.set_state(BoardSlot::HIT_MISSED);
        std::shared_ptr<Ship> ship = slot.get_ship();
        ship->set_health(ship->get_health()-1);
        return true;
    }
    get_slot(target).set_state(BoardSlot::HIT);
    return true;
}

HitAction::HitAction(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board) : Action(board_,enemy_board) {

}
