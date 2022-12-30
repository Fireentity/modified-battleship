#include "player/Human.h"


Human::Human(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board) : Player{board,
                                                                                                      enemy_board} {

}

void Human::place_ships_inside_board() {
    int i = 0;
    while (i < Player::available_ships.size()) {
        std::cout << "Inserisci le coordinate della prua e della poppa [" << Ship::to_string(available_ships[i])
                  << "]: ";

        if (place_in_board(available_ships[i])) {
            get_board()->print_with_ships();
            i++;
        } else {
            std::cout
                    << "Posiziona orizzontalmente o verticalmente la nave inserendo le coordinate di poppa e prua (XY XY)"
                    << std::endl;
        }
    }
}

bool Human::place_in_board(Ship::Ships ship) {
    std::string input;
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), toupper); //trasforma la stringa in maiuscola
    if (!std::regex_match(input, inputRegex)) {
        return false;
    }

    //Applico la regex sull'input dell'utente
    std::smatch match;
    std::regex_search(input, match, inputRegex);

    //Coordinate della prua
    std::string first_coordinate = match[1];
    std::string second_coordinate = match[2];

    //Coordinate della poppa
    std::string third_coordinate = match[3];
    std::string fourth_coordinate = match[4];

    Point bow{std::stoi(second_coordinate), Point::to_index(first_coordinate[0])};
    Point stern{std::stoi(fourth_coordinate), Point::to_index(third_coordinate[0])};

    return Ship::instantiate_ship(ship, bow, stern, get_board(), get_enemy_board());
}

void Human::do_move() {
    while (!ask_action()) {
        std::cout << "Azione non valida" << std::endl;
    }
}

bool Human::ask_action() {
    std::cout << "Inserisci l'azione che vuoi eseguire: ";
    std::string input;
    std::getline(std::cin, input);




}

