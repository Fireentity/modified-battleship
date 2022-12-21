#include "player/Human.h"

const int Human::firstUpperCaseLetter = 101;
const std::regex Human::inputCharacterRegex = std::regex{R"([A-M])"};
//Permette di verificare il formato dell'input dell'utente
const std::regex Human::inputRegex = std::regex{R"(^([A-M])(\d{1,2}) ([A-M])(\d{1,2})$)"};

std::shared_ptr<Board> Human::place_ships_inside_board() {
    int i = 0;
    while (i < Player::available_ships.size()) {
        std::cout << "Inserisci le coordinate della prua e della poppa [" << Player::to_string(available_ships[i])
                  << "]: ";

        if (place_board(available_ships[i])) {
            //TODO creare un metodo per stampare la griglia
            //std::cout << board_;
            i++;
        } else {
            std::cout << "Posiziona orizzontalmente o verticalmente la nave inserendo le coordinate di poppa e prua (XY XY)"
                    << std::endl;
        }
    }
}

int Human::to_index(const std::string &slot) {
    if (!std::regex_match(slot, Human::inputCharacterRegex)) {
        throw std::invalid_argument("Invalid input format");
    }

    char character = slot.at(0);
    return character - firstUpperCaseLetter;
}

bool Human::place_board(Ships ship) {
    std::string input;
    std::cin >> input;

    if (!std::regex_match(input, inputRegex)) {
        return false;
    }

    //Applico la regex sull'input dell'utente
    std::smatch match;
    std::regex_search(input, match, inputRegex);

    //Coordinate della prua
    std::string first_char = match[1];
    std::string second_char = match[2];

    //Coordinate della poppa
    std::string third_char = match[3];
    std::string fourth_char = match[4];

    Point bow{to_index(first_char), std::stoi(second_char)};
    Point stern{to_index(third_char), std::stoi(fourth_char)};

    return Player::factory.at(ship)(bow, stern, std::shared_ptr<Board>{&board_});
}

void Human::do_move(Board &enemy_board) {
    while (!ask_input(enemy_board)) {
        std::cout << "Azione non valida" << std::endl;
    }
}

bool Human::ask_input(Board &enemy_board) {
    std::cout << "Inserisci l'azione che vuoi eseguire: ";
    std::string input;
    std::cin >> input;

    if (!std::regex_match(input, inputRegex)) {
        return false;
    }

    //Applico la regex sull'input dell'utente
    std::smatch match;
    std::regex_search(input, match, inputRegex);

    //Coordinate della prua
    std::string first_char = match[1];
    std::string second_char = match[2];

    //Coordinate della poppa
    std::string third_char = match[3];
    std::string fourth_char = match[4];

    Point ship_position{to_index(first_char), std::stoi(second_char)};
    Point destination{to_index(third_char), std::stoi(fourth_char)};

    BoardSlot &slot = board_.get_slot(ship_position);
    if (!slot.has_ship()) {
        return false;
    }

    return slot.get_ship_piece()->get_ship()->do_action(destination, enemy_board);
}
