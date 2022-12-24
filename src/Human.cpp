#include "Human.h"

//Permette di verificare il formato dell'input dell'utente
const std::regex Human::inputRegex = std::regex{R"(^([A-Z])(\d{1,2}) ([A-Z])(\d{1,2})$)"};

std::shared_ptr<DefenceBoard> Human::place_ships_inside_board() {
    std::string input;
    std::cin>>input;
    //Controlla se la stringa è del formato descritto nella regex
    if(!std::regex_match(input,inputRegex)) {
        throw std::invalid_argument("Invalid date format");
    }

    std::smatch match;
    std::regex_search(input,match,inputRegex);
    std::string first_char = match[1];
    std::string second_char = match[2];

    std::string third_char = match[3];
    std::string fourth_char = match[4];

}
