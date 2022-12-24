#include "ship/Supporter.h"

const char Supporter::piece = 'S';
const char Supporter::damagedPiece = 's';
const unsigned short Supporter::range = 1;
const unsigned short Supporter::breadth = 1;
const unsigned short Supporter::length = 3;
const unsigned short Supporter::max_health = 3;

//TODO make this code a copy-paste from ArmouredShip solving shared_ptr problem
Supporter::Supporter(const std::vector<Point> &positions, const Point &center, int width, int height,
                     const std::shared_ptr<DefenceBoard> &board) : LinearShip{center, width, height, max_health,
                                                                              max_health, board} {

    std::shared_ptr<Supporter> ship{};
    ship.reset(this);
    for (int i = 0; i < positions.size(); i++) {
        pieces_[i] = std::make_shared<ShipPiece>(positions[i], board, ship);
        pieces_[i]->move_to(positions[i]);
    }

    //Mette i pezzi nella board
    for (auto &iterated_piece: pieces_) {
        iterated_piece->move_to(iterated_piece->get_position().x, iterated_piece->get_position().y);
    }
}


std::shared_ptr<Supporter> Supporter::make_ship_or_null(int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &board) {

    if (board->is_out(x, y)) {
        return nullptr;
    }

    Point center{x, y};

    std::vector<Point> positions{length};

    //Calcola tutti punti occupati dalla barca nella board
    for (int i = 0; i < length; i++) {
        if (horizontal) {
            x += -(length / 2) + i;
        } else {
            y += -(length / 2) + i;
        }

        positions[i] = {x, y};
    }

    //Controlla che tutti i punti dove sarà posizionata la barca rispettino le condizioni specificate
    bool can_place = std::any_of(positions.begin(), positions.end(), [board](Point &position) {
        return board->is_out(position) || board->get_slot(position).has_ship();
    });

    if (!can_place) {
        return nullptr;
    }

    //Viene allocato manualmente perché il costruttore di ArmouredShip è privato
    //TODO check if this is correct
    Supporter ship{positions, center, horizontal ? length : breadth, horizontal ? breadth : length,board};
    return std::make_shared<Supporter>(ship);
}

char Supporter::get_character() const {
    return piece;
}

char Supporter::get_damaged_character() const {
    return damagedPiece;
}

//In questo caso enemy_board non viene utilizzato in quanto la nave di supporto non agisce sulla tabella avversara
bool Supporter::do_action(int x, int y, DefenceBoard &enemy_board) {
    if (health_ == 0) {
        return false;
    }

    if (defence_board_->is_out(x, y)) {
        return false;
    }

    if (!is_valid_position(x, y)) {
        return false;
    }

    move(x, y);

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
