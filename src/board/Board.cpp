#include "board/Board.h"

bool Board::is_out(unsigned int x, unsigned int y) {
    return x > Board::width || y > Board::height;
}

bool Board::is_out(const Point &point) {
    return point.get_x() > width || point.get_y() > height;
}

const BoardSlot &Board::get_slot(unsigned int x, unsigned int y) const {
    if (is_out(x, y)) {
        throw std::invalid_argument("Position out of bounds");
    }
    //Le coordinate sono invertite perché si usano i normali assi cartesiani e non le coordinate delle matrici
    return this->board_[y][x];
}

const BoardSlot &Board::get_slot(const Point &point) const {
    return get_slot(point.get_x(), point.get_y());
}

BoardSlot &Board::get_slot(const Point &point) {
    return board_[point.get_y()][point.get_x()];
}

BoardSlot &Board::get_slot(unsigned int x, unsigned int y) {
    return board_[y][x];
}

bool Board::insert_ship(Ship ship) {
    std::shared_ptr<Ship> shared_ptr = std::make_shared<Ship>(ship);
    ship.for_each_piece([shared_ptr,this](const ShipPiece &piece) {
        this->board_[piece.get_position().get_y()][piece.get_position().get_x()].set_ship(shared_ptr);
    });
}

bool Board::move_ship(const Point &ship_center, const Point &destination) {
    BoardSlot &slot = board_[ship_center.get_y()][ship_center.get_x()];
    //Controlliamo ship_center sia effettivamente il centro della nave da spostare
    std::shared_ptr<Ship> ship = slot.get_ship();
    if(ship->get_center() != ship_center) {
        return false;
    }

    Point translation = destination-ship_center;

    std::vector<Point> positions{ship->get_pieces_amount()};

    auto iter = positions.begin();

    slot.get_ship()->for_each_piece([iter,translation](ShipPiece &piece) {
        (*iter) = piece.get_position() + translation;
    });

    //Controllo che non ci siano altre navi nella destinazione
    //Se c'è una nave controllo che non sia quella che sto spostando
    bool can_move = std::any_of(positions.begin(),positions.end(),[this,ship](const Point &position){
       return get_slot(position).get_ship() != ship;
    });

    if(!can_move) {
        return false;
    }

    iter = positions.begin();
    slot.get_ship()->for_each_piece([iter,this,ship](ShipPiece &piece) {
        piece.move_to((*iter));
        get_slot(piece.get_position()).remove_ship();
        get_slot(*iter).set_ship(ship);
    });

    return true;
}

Board::Action::Action(Board &board, Board &enemy_board): board_{board}, enemy_board_{enemy_board} {

}

BoardSlot &Board::Action::get_slot(const Point &point) {
    return board_.get_slot(point);
}

BoardSlot &Board::Action::get_slot(unsigned int x, unsigned int y) {
    return board_.get_slot(x,y);
}

BoardSlot &Board::Action::get_enemy_slot(const Point &point) {
    return enemy_board_.get_slot(point);
}

BoardSlot &Board::Action::get_enemy_slot(unsigned int x, unsigned int y) {
    return enemy_board_.get_slot(x,y);
}

bool Board::Action::move_ship(const Point &ship_center, const Point &destination) {
    return board_.move_ship(ship_center,destination);
}
