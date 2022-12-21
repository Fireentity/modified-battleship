#include <array>
#include "ship/ArmouredShip.h"

const char ArmouredShip::piece = 'C';
const char ArmouredShip::damagedPiece = 'c';
const int ArmouredShip::breadth = 1;
const int ArmouredShip::length = 5;
const int ArmouredShip::max_health = 5;

//Il costruttore posiziona anche la nave nella board_ questo perché potenzialmente ogni nave ha una forma diversa
//quindi il codice che implementa l'inserimento della nave nella scacchiera dovrebbe stare in ciascuna
//classe derivata della classe Ship.
//Invece di usare un metodo place si è preferito usare il costruttore in modo da evitare di invalidare lo
//stato interno della nave. Non possono esserci oggetti Ship che hanno posizioni non valide nel loro stato interno.
//Nel costruttore non vengono fatti controlli sulla validità della posizione in quanto gli oggetti sono chiamati tramite
//static method factory (design pattern)
ArmouredShip::ArmouredShip(const std::vector<Point> &positions, const Point &center, int width, int height,
                           const std::shared_ptr<Board> &defence_board) : LinearShip{center, width, height,
                                                                                     max_health, max_health,
                                                                                     defence_board} {

    std::shared_ptr<ArmouredShip> ship{};
    ship.reset(this);
    for (int i = 0; i < positions.size(); i++) {
        pieces_[i] = std::make_shared<ShipPiece>(positions[i], defence_board, ship);
        pieces_[i]->move_to(positions[i]);
    }

    //Mette i pezzi nella board_
    for (auto &iterated_piece: pieces_) {
        iterated_piece->move_to(iterated_piece->get_position());
    }
}


std::shared_ptr<Ship>
ArmouredShip::make_ship_or_null(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board) {

    if (bow.get_x() != stern.get_x() && bow.get_y() != stern.get_y()) {
        return nullptr;
    }

    //Controllo che la distanza tra poppa e prua sia uguale alla lunghezza della nave
    if (bow.squared_distance(stern) != std::pow(length, 2)) {
        return nullptr;
    }

    if (board->is_out(bow) || board->is_out(stern)) {
        return nullptr;
    }

    bool horizontal = stern.get_y() == bow.get_y();

    Point center = bow.middle_point(stern);

    std::vector<Point> positions{length};

    //Calcola tutti punti occupati dalla barca nella board_
    for (int i = 0; i < length; i++) {
        if (horizontal) {
            positions[i] = {center.get_x() - (length / 2) + i, 0};
        } else {
            positions[i] = {0, center.get_x() - (length / 2) + i};
        }

    }

    //Controlla che tutti i punti dove sarà posizionata la barca rispettino le condizioni specificate
    bool can_place = std::any_of(positions.begin(), positions.end(), [board](Point &position) {
        return Board::is_out(position) || board->get_slot(position).has_ship();
    });

    if (!can_place) {
        return nullptr;
    }

    return std::shared_ptr<ArmouredShip>{new ArmouredShip{positions,
                                                          center,
                                                          horizontal ? length : breadth,
                                                          horizontal ? breadth : length,
                                                          board}};
}

bool ArmouredShip::do_action(const Point &target, Board &enemy_board) {
    if (health_ == 0) {
        return false;
    }

    if (Board::is_out(target)) {
        return false;
    }

    std::shared_ptr<Ship> ship = enemy_board.get_slot(target).get_ship_piece()->get_ship();
    if (ship == nullptr) {
        enemy_board.get_slot(target).set_state(BoardSlot::HIT_MISSED);
    } else {
        ship->set_health(ship->get_health() - 1);
        enemy_board.get_slot(target).set_state(BoardSlot::HIT);
    }

    return true;
}

char ArmouredShip::get_damaged_character() const {
    return damagedPiece;
}

char ArmouredShip::get_character() const {
    return piece;
}


