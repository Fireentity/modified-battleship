//Alberto Bottari 2034728

#include "player/Player.h"

Player::Player(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board, const std::string &name)
        : board_{board}, enemy_board_{enemy_board}, name_{name} {
}

std::shared_ptr<const Board> Player::get_board() const {
    return board_;
}

void Player::register_command(const std::shared_ptr<Command> &command) {
    commands_.push_back(command);
}

bool Player::dispatch_command(const std::string &command) {
    for (auto &iterated_command: commands_) {
        if (iterated_command->check_command(command)) {
            return iterated_command->execute(command);
        }
    }
    return false;
}
