#include "commands/ShipActionCommand.h"

ShipActionCommand::ShipActionCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Logger> &logger,
                                     const std::function<void()> &execute_then) : ShipCommand(board, logger),
                                                                                  execute_then_{execute_then} {

}

bool ShipActionCommand::execute_action(const Point &ship_center, const Point &target) {
    if (!board_->at(ship_center).has_ship()) {
        return false;
    }

    std::shared_ptr<const Ship> ship = board_->at(ship_center).get_ship();

    //Controllo se il punto è il centro della nave
    if (ship->get_center() != ship_center) {
        return false;
    }

    if (ship->do_action(target)) {
        logger_->log_action(ship_center.to_string() + " " + target.to_string());
        execute_then_();
        return true;
    }

    return false;
}
