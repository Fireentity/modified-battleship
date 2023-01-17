//Lorenzo Croce 2034738

#include "actions/Action.h"

Action::Action(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board)
        : board_{board}, enemy_board_{enemy_board} {
}
