#ifndef SHIPPLACECOMMAND_H
#define SHIPPLACECOMMAND_H

#include "ShipCommand.h"

class ShipPlaceCommand : public ShipCommand {
private:
    int index;
    std::shared_ptr<Board> enemy_board_;
public:
    static const std::vector<Ship::Ships> availableShips;

    ShipPlaceCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                     const std::shared_ptr<Logger> &logger);

    bool execute_action(const Point &bow, const Point &stern) override;

    bool execute_action(const Point &top_left_corner, bool horizontal);
};

#endif //SHIPPLACECOMMAND_H
