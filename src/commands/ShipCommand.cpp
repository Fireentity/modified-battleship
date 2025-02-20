//Alberto Bottari 2034728

#include "commands/ShipCommand.h"

const std::regex ShipCommand::inputRegex = std::regex{R"(^([A-Z])(\d+) ([A-Z])(\d+)$)"};
const std::regex ShipCommand::inputCharacterRegex = std::regex{R"([A-IL-N])"};

ShipCommand::ShipCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Logger> &logger) : board_{board},
                                                                                                       logger_{logger} {

}

bool ShipCommand::check_command(const std::string &argument) {
    return std::regex_match(argument, inputRegex);
}

bool ShipCommand::execute(const std::string &argument) {

    //Applico la regex sull'input dell'utente
    std::smatch match;
    std::regex_search(argument, match, inputRegex);

    //Coordinate della prua
    std::string first_coordinate = match[1];
    std::string second_coordinate = match[2];

    //Coordinate della poppa
    std::string third_coordinate = match[3];
    std::string fourth_coordinate = match[4];

    if (!std::regex_match(first_coordinate, inputCharacterRegex) ||
        !std::regex_match(third_coordinate, inputCharacterRegex)) {
        return false;
    }

    Point first_point{std::stoi(second_coordinate), first_coordinate[0]};
    Point second_point{std::stoi(fourth_coordinate), third_coordinate[0]};

    return execute(first_point, second_point);
}

bool ShipCommand::execute(const Point &first_point, const Point &second_point) {
    return execute_action(first_point, second_point);
}