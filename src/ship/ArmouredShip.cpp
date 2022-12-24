#include <array>
#include "ship/ArmouredShip.h"

const char ArmouredShip::piece = 'C';
const char ArmouredShip::damagedPiece = 'c';
const int ArmouredShip::breadth = 1;
const int ArmouredShip::length = 5;
const int ArmouredShip::max_health = 5;

//Il costruttore posiziona anche la nave nella board e lancia eccezione se non la si può posizionare
ArmouredShip::ArmouredShip(const std::vector<Point> &positions, const Point &center, int width, int height,
                           const std::shared_ptr<DefenceBoard> &defence_board) : LinearShip{center, width, height,
                                                                                            max_health, max_health,
                                                                                            defence_board} {

    std::shared_ptr<ArmouredShip> ship{};
    ship.reset(this);
    for (int i = 0; i < positions.size(); i++) {
        pieces_[i] = std::make_shared<ShipPiece>(positions[i], defence_board, ship);
        pieces_[i]->move_to(positions[i]);
    }

    //Mette i pezzi nella board
    for (auto &iterated_piece: pieces_) {
        iterated_piece->move_to(iterated_piece->get_position().x, iterated_piece->get_position().y);
    }
}


std::shared_ptr<ArmouredShip>
ArmouredShip::make_ship_or_null(int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board) {

    if (defence_board->is_out(x, y)) {
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
    bool can_place = std::any_of(positions.begin(), positions.end(), [defence_board](Point &position) {
        return defence_board->is_out(position) || defence_board->get_slot(position).has_ship();
    });

    if (!can_place) {
        return nullptr;
    }

    //Viene allocato manualmente perché il costruttore di ArmouredShip è privato
    //TODO check if this is correct
    ArmouredShip ship{positions, center, horizontal ? length : breadth, horizontal ? breadth : length, defence_board};
    return std::make_shared<ArmouredShip>(ship);
}

bool ArmouredShip::do_action(int x, int y, DefenceBoard &enemy_board) {
    if (health_ == 0) {
        return false;
    }

    if (enemy_board.is_out(x, y)) {
        return false;
    }

    std::shared_ptr<Ship> ship = enemy_board.get_slot(x, y).get_ship_piece()->get_ship();
    if (ship == nullptr) {
        enemy_board.get_slot(x, y).set_state(BoardSlot::HIT_MISSED);
    } else {
        ship->set_health(ship->get_health() - 1);
        enemy_board.get_slot(x, y).set_state(BoardSlot::HIT);
    }

    return true;
}

char ArmouredShip::get_damaged_character() const {
    return damagedPiece;
}

char ArmouredShip::get_character() const {
    return piece;
}


