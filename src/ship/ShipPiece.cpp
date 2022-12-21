#include "ship/ShipPiece.h"

ShipPiece::ShipPiece(const Point &position, const std::shared_ptr<Board> &defence_board,
                     const std::shared_ptr<Ship> &ship) : position_{position}, defence_board_{defence_board},
                                                          ship_{ship} {

}

ShipPiece::ShipPiece() : position_{0,0}, defence_board_(), ship_(), hit_(false) {

}

void ShipPiece::move_to(const Point &point) {
    //Si crea un nuovo shared_ptr
    std::shared_ptr<ShipPiece> piece = std::make_shared<ShipPiece>(*this);
    //Prima viene rimosso il pezzo dalla posizione precedente
    defence_board_->get_slot(position_).remove_ship_piece();
    //Poi viene inserito nella nuova posizione
    defence_board_->get_slot(point).set_ship_piece(piece);
    //Viene aggiornata la posizione corrente
    position_ = point;
}

bool ShipPiece::is_valid_position(const Point &point) {
    if(defence_board_->is_out(point)) {
        return false;
    }
    //Controlla se il pezzo di barca presente nella griglia è un pezzo della propria barca che sarà a sua volta spostato
    if(defence_board_->get_slot(point).has_ship() && defence_board_->get_slot(point).get_ship_piece()->get_ship() == ship_) {
        return true;
    }

    return !defence_board_->get_slot(point).has_ship();
}

const Point &ShipPiece::get_position() {
    return position_;
}

bool ShipPiece::is_hit() {
    return hit_;
}

void ShipPiece::hit() {
    hit_ = true;
}

std::shared_ptr<Ship> ShipPiece::get_ship() {
    return ship_;
}
