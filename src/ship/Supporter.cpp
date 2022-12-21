#include "ship/Supporter.h"

const char Supporter::piece = 'S';
const char Supporter::damagedPiece = 's';
const unsigned short Supporter::range = 1;
const unsigned short Supporter::breadth = 1;
const unsigned short Supporter::length = 3;
const unsigned short Supporter::max_health = 3;

//TODO make this code a copy-paste from ArmouredShip solving shared_ptr problem
Supporter::Supporter(const std::vector<Point> &positions, const Point &center, int width, int height,
                     const std::shared_ptr<Board> &board) : LinearShip{center, width, height, max_health,
                                                                       max_health, board} {

    std::shared_ptr<Supporter> ship{this};
    for (int i = 0; i < positions.size(); i++) {
        pieces_[i] = std::make_shared<ShipPiece>(positions[i], board, ship);
        pieces_[i]->move_to(positions[i]);
    }

    //Mette i pezzi nella board_
    for (auto &iterated_piece: pieces_) {
        iterated_piece->move_to(iterated_piece->get_position());
    }
}


std::shared_ptr<Ship> Supporter::make_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board) {

    if(bow.get_x() != stern.get_x() && bow.get_y() != stern.get_y()){
        return nullptr;
    }

    //Controllo che la distanza tra poppa e prua sia uguale alla lunghezza della nave
    if(bow.squared_distance(stern) != std::pow(length,2)) {
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
            positions[i] = {center.get_x() - (length/2) + i, 0};
        } else {
            positions[i] = {0,center.get_x() - (length/2) + i};
        }

    }

    //Controlla che tutti i punti dove sarà posizionata la barca rispettino le condizioni specificate
    bool can_place = std::any_of(positions.begin(), positions.end(), [board](Point &position) {
        return Board::is_out(position) || board->get_slot(position).has_ship();
    });

    if (!can_place) {
        return nullptr;
    }

    //TODO check if this is correct
    return std::shared_ptr<Supporter>(new Supporter{positions,
                                                     center,
                                                     horizontal ? length : breadth,
                                                     horizontal ? breadth : length,
                                                     board});
}

char Supporter::get_character() const {
    return piece;
}

char Supporter::get_damaged_character() const {
    return damagedPiece;
}

//In questo caso enemy_board non viene utilizzato in quanto la nave di supporto non agisce sulla tabella avverisara
bool Supporter::do_action(const Point &target, Board &enemy_board) {
    if (health_ == 0) {
        return false;
    }

    if (defence_board_->is_out(target)) {
        return false;
    }

    if (!is_valid_position(target)) {
        return false;
    }

    move(target);

    int center_x = get_center_x() - (range / 2);
    int center_y = get_center_x() - (range / 2);
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < range; j++) {
            std::shared_ptr<Ship> ship = defence_board_->get_slot(center_x + j,
                                                                  center_y + i).get_ship_piece()->get_ship();
            if (ship != nullptr) {
                ship->set_health(ship->get_max_health());
            }
        }
    }

    return true;
}
