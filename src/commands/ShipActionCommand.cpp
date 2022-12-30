#include "commands/ShipActionCommand.h"

const std::regex ShipActionCommand::inputRegex = std::regex{R"(^([A-Z])(\d+) ([A-Z])(\d+)$)"};
const std::regex ShipActionCommand::inputCharacterRegex = std::regex{R"([A-IL-N])"};

ShipActionCommand::ShipActionCommand(const std::shared_ptr<Board> &board, const Logger &logger) : board_{board}, logger_{logger} {

}

bool ShipActionCommand::check_command(const std::string &argument) {
    return std::regex_match(argument,inputRegex);
}

bool ShipActionCommand::execute(const std::string &argument) {
    std::string input = argument;
    //In template: type 'std::basic_string<char>' does not provide a call operator
    //trasforma la stringa in maiuscola
    std::transform(input.begin(), input.end(), input.begin(), toupper);
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

    Point ship_center{std::stoi(second_coordinate), first_coordinate[0]};
    Point destination{std::stoi(fourth_coordinate), third_coordinate[0]};

    return execute(ship_center,destination);
}

bool ShipActionCommand::execute(const Point &ship_center, const Point &destination) {
    if(!board_->at(ship_center).has_ship()) {
        return false;
    }

    std::shared_ptr<const Ship> ship = board_->at(ship_center).get_ship();

    //Controllo se il punto è il centro della nave
    if(ship->get_center() != ship_center) {
        return false;
    }

    if(ship->do_action(destination) ){
        logger_.log();
        return true;
    }

    return false;
}
