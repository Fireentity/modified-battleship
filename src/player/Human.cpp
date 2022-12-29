#include "player/Human.h"

const std::regex Human::inputCharacterRegex = std::regex{R"([A-IL-N])"};
//Permette di verificare il formato dell'input dell'utente
const std::regex Human::inputRegex = std::regex{R"(^([A-Z])(\d+) ([A-Z])(\d+)$)"};

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

int Human::to_index(const std::string &slot) {
    if (!std::regex_match(slot, Human::inputCharacterRegex)) {
        throw std::invalid_argument("Invalid input format");
    }

    char character = slot.at(0);
    if (slot[0] > 'I' && slot[0] < 'Z') { //toglie due per le lettere dopo jk
        return character - firstUpperCaseLetter - 2;
    }
    return character - firstUpperCaseLetter;
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

    Point bow{std::stoi(second_coordinate), to_index(first_coordinate)};
    Point stern{std::stoi(fourth_coordinate), to_index(third_coordinate)};

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
    if(Board::is_out(destination) || Board::is_out(ship_position)){
        return false;
    }
    const BoardSlot &slot = get_board()->at(ship_position);
    if (!slot.has_ship()) {
        return false;
    }

    return slot.get_ship()->do_action(destination);
}

