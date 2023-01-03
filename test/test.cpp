//TODO remove this file
#include "Game.h"

int main () {
    std::shared_ptr<Board> board_1 = std::make_shared<Board>();
    std::shared_ptr<Board> board_2 = std::make_shared<Board>();
    board_1->insert_ship(std::make_shared<Submarine>(Point{2,3},board_1,board_2));
    board_1->at(2,3).get_ship()->do_action(Point{3,5});
    board_1->print_with_ships();
}