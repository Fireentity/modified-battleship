//Alberto Bottari 2034728

#include "commands/ShipPlaceCommand.h"

const std::vector<ShipPlaceCommand::Ships> ShipPlaceCommand::availableShips = {
        Ships::ARMOURED, Ships::ARMOURED, Ships::ARMOURED, Ships::SUPPORT, Ships::SUPPORT,
        Ships::SUPPORT, Ships::SUBMARINE, Ships::SUBMARINE,
};

/**
 *
 * @param board la board sulla quale posizionare la navi
 * @param enemy_board la board dell'avversario
 * @param logger il logger per loggare le azioni eseguite
 */
ShipPlaceCommand::ShipPlaceCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                                   const std::shared_ptr<Logger> &logger) : ShipCommand(board, logger),
                                                                            enemy_board_{enemy_board},
                                                                            index_{0} {
}

/**
 * Permette di instanziare e posizionare una nave nella board in base al tipo di nave passato come parametro.
 * @param ship_type il tipo della nave da creare
 * @param top_left_corner il punto in alto a sinistra della nave
 * @param horizontal indica se si vuole posizionare la nave in orizzontale o in verticale
 * @param board la board all'interno della quale si intende posizionare la nave
 * @param enemy_board la board dell'avversario che serve per inizializzare l'azione che deve eseguire la nave
 * @return ritorna true se la nave è stata correttamente posizionata false altrimenti
 */
bool ShipPlaceCommand::instantiate_ship(Ships ship_type, const Point &top_left_corner, bool horizontal,
                            const std::shared_ptr<Board> &board,
                            const std::shared_ptr<Board> &enemy_board) {
    switch (ship_type) {
        case ARMOURED:
            return board->insert_ship(std::make_shared<Armoured>(top_left_corner, horizontal, board, enemy_board));
        case SUPPORT:
            return board->insert_ship(std::make_shared<Supporter>(top_left_corner, horizontal, board, enemy_board));
        case SUBMARINE:
            return board->insert_ship(std::make_shared<Submarine>(top_left_corner, board, enemy_board));
    }
    throw std::invalid_argument("Invalid ship type");
}

/**
 *
 * @param bow la prua della nave
 * @param stern la poppa della nave
 * @return ritorna true se la nave è posizionata correttamente false altrimenti
 */
bool ShipPlaceCommand::execute_action(const Point &bow, const Point &stern) {
    if (index_ >= availableShips.size()) {
        return false;
    }

    Ships ship_type = availableShips[index_];

    int point_distance = get_length(ship_type) - 1;
    if (bow.squared_distance(stern) != std::pow(point_distance, 2)) {
        return false;
    }
    if (bow.get_x() != stern.get_x() && bow.get_y() != stern.get_y()) {
        return false;
    }
    if (Board::is_out(bow) || Board::is_out(stern)) {
        return false;
    }

    bool horizontal = bow.get_y() == stern.get_y();
    Point top_left_corner = Point{std::min(bow.get_x(), stern.get_x()), std::min(bow.get_y(), stern.get_y())};

    bool was_placed = instantiate_ship(ship_type, top_left_corner, horizontal, board_, enemy_board_);
    if (was_placed) {
        logger_->log(bow.to_string() + " " + stern.to_string()).log("\n");
        index_++;
    }
    return was_placed;
}

/**
 * Associa ad ogni tipo di nave una stringa. Poteva essere implementato anche con una mappa statica
 * e avrebbe avuto complessità O(1) ma lo si è ritenuto inutile
 * @param ship il tipo di nave di cui ottenere la stringa
 * @return ritorna la stringa associata al tipo di nave dato in input
 */
std::string ShipPlaceCommand::to_string(Ships ship) {
    switch (ship) {
        case ARMOURED: return "Corazzata";
        case SUBMARINE: return "Sottomarino";
        case SUPPORT: return "Supporto";
    }
    throw std::invalid_argument("Invalid ship type");
}

/**
 * Associa ad ogni tipo di nave la lunghezza di essa. Poteva essere implementato anche con una mappa statica
 * e avrebbe avuto complessità O(1) ma lo si è ritenuto inutile
 * @param ship il tipo di nave di cui ottenere la lunghezza
 * @return ritorna la lunghezza associata al tipo di nave dato in input
 */
int ShipPlaceCommand::get_length(Ships ship) {
    switch (ship) {
        case ARMOURED: return Armoured::length;
        case SUBMARINE: return Submarine::length;
        case SUPPORT: return Supporter::length;
    }
    throw std::invalid_argument("Invalid ship type");
}

/**
 *
 * @param top_left_corner il punto in alto a sinistra della nave
 * @param horizontal l'orientamento della nave
 * @return ritorna true se la nave è posizionata correttamente false altrimenti
 */
bool ShipPlaceCommand::execute_action(const Point &top_left_corner, bool horizontal) {
    if (index_ >= availableShips.size()) {
        return false;
    }

    Ships ship_type = availableShips[index_];
    int point_distance = get_length(ship_type) - 1;
    Point stern = horizontal ? top_left_corner.add_x(point_distance) : top_left_corner.add_y(point_distance);
    std::shared_ptr<Board> board = board_;
    std::shared_ptr<Board> enemy_board = enemy_board_;
    bool was_placed = instantiate_ship(ship_type, top_left_corner, horizontal, board, enemy_board);
    if (was_placed) {
        logger_->log(top_left_corner.to_string() + " " + stern.to_string()).log("\n");
        index_++;
        return true;
    }
    return false;
}
