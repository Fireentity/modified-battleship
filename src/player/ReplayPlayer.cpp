#include "player/ReplayPlayer.h"

void ReplayPlayer::place_ships_inside_board() {
    int i = 0;
    while (i < ShipPlaceCommand::availableShips.size() && *moves_iterator_ != end_iterator_) {
        if (place_command_.execute(**moves_iterator_)) {
            (*moves_iterator_)++;
            i++;
        }
    }
    print();
}

void ReplayPlayer::do_move() {
    while (*moves_iterator_ != end_iterator_) {
        if (dispatch_command(**moves_iterator_)) {
            (*moves_iterator_)++;
        } else {
            throw std::invalid_argument("Invalid move from file!");
        }
        std::ofstream file_stream_{file_name_, std::ios::app};
        if (!file_stream_.is_open()) {
            file_stream_.close();
            throw std::invalid_argument("Cannot open file");
        }

    }
}

ReplayPlayer::ReplayPlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                           const std::shared_ptr<Logger> &logger, const std::shared_ptr<Logger> &output_logger,
                           const std::function<void()> &change_turn,
                           const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
                           const std::vector<std::string>::const_iterator &end_iterator,
                           const std::string &file_name) : Player{board, enemy_board},
                                                           place_command_{board, enemy_board, logger},
                                                           moves_iterator_{moves_iterator},
                                                           end_iterator_{end_iterator},
                                                           file_name_{file_name},
                                                           logger_{logger} {
    register_command(std::make_shared<ShipActionCommand>(board, logger, change_turn));
}

void ReplayPlayer::print() {

    if (print_in_terminal_) {
        std::cout << (*board_);
    } else {
        std::ofstream file_stream_{file_name_, std::ios::app};
        if (!file_stream_.is_open()) {
            file_stream_.close();
            throw std::invalid_argument("Cannot open file");
        }

        file_stream_ << (*board_) << std::endl;
        file_stream_.close();
    }
}
