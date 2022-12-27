#include "board/Board.h"
//Ship viene inclusa soltanto nel file .cpp per risolvere la dipendenza circolare
#include "ship/Ship.h"

bool Board::is_out(unsigned int x, unsigned int y) {
    return x >= Board::width || y >= Board::height;
}

bool Board::is_out(const Point &point) {
    return is_out(point.get_x(), point.get_y());
}

const BoardSlot &Board::at(unsigned int x, unsigned int y) const {
    if (is_out(x, y)) {
        throw std::invalid_argument("Position out of bounds");
    }
    //Le coordinate sono invertite perché si usano i normali assi cartesiani e non le coordinate delle matrici
    return this->board_[y][x];
}

const BoardSlot &Board::at(const Point &point) const {
    return at(point.get_x(),point.get_y());
}

BoardSlot &Board::get_slot(const Point &point) {
    return board_[point.get_y()][point.get_x()];
}

BoardSlot &Board::get_slot(unsigned int x, unsigned int y) {
    return board_[y][x];
}

bool Board::insert_ship(const std::shared_ptr<Ship> &ship) {
    bool unable_to_place = std::any_of(ship->get_pieces().begin(),ship->get_pieces().end(),[this](const ShipPiece &piece){
        return Board::is_out(piece.get_position()) || at(piece.get_position()).has_ship();
    });
    if(unable_to_place) {
        return false;
    }
    std::for_each(ship->get_pieces().begin(), ship->get_pieces().end(),[this, ship](const ShipPiece &piece){
        this->board_[piece.get_position().get_y()][piece.get_position().get_x()].set_ship(ship);
    });
    ships_.push_back(ship);
    return true;
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

const std::vector<std::shared_ptr<Ship>> &Board::get_ships() const {
    return ships_;
}

void Board::print_with_ships() const{

    std::cout<<"\t";
    for(int i = 0; i < Board::width; i++) {
        std::cout<<"  "<<i<<" ";
    }

    std::cout<<std::endl;
    for(int i = 0; i < Board::height; i++) {

        std::cout<<"\t";

        for(int j = 0; j < Board::width; j++) {
            std::cout<<"+---";
        }
        std::cout<<"+"<<std::endl;

        char index = 'A' + i;
        std::cout<< index <<"\t";

        for(int j = 0; j < Board::width; j++) {
            std::cout<<"| "<< at(j,i).get_piece(j,i)<<" ";
        }
        std::cout<<"|"<<std::endl;
    }

    std::cout<<"\t";

    for(int j = 0; j < Board::width; j++) {
        std::cout<<"+---";
    }
    std::cout<<"+"<<std::endl;
}

void Board::print_without_Ships() const {
    std::cout<<"\t";
    for(int i = 0; i < Board::width; i++) {
        std::cout<<"  "<<i<<" ";
    }

    std::cout<<"\t";
    for(int i = 0; i < Board::width; i++) {
        std::cout<<"  "<<i<<" ";
    }

    std::cout<<std::endl;
    for(int i = 0; i < Board::height; i++) {

        std::cout<<"\t";

        for(int j = 0; j < Board::width; j++) {
            std::cout<<"+---";
        }
        std::cout<<"+"<<std::endl;

        char index = 'A' + i;
        std::cout<< index <<"\t";

        for(int j = 0; j < Board::width; j++) {
            std::cout<<"| "<< BoardSlot::to_character(at(j,i).get_state())<<" ";
        }
        std::cout<<"|"<<std::endl;
    }

    std::cout<<"\t";

    for(int j = 0; j < Board::width; j++) {
        std::cout<<"+---";
    }
    std::cout<<"+"<<std::endl;
}

Board::Action::Action(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board): board_{board}, enemy_board_{enemy_board} {

}

BoardSlot &Board::Action::get_slot(const Point &point) {
    return board_->get_slot(point);
}

BoardSlot &Board::Action::get_enemy_slot(const Point &point) {
    return enemy_board_->get_slot(point);
}

BoardSlot &Board::Action::get_enemy_slot(unsigned int x, unsigned int y) {
    return enemy_board_->get_slot(x,y);
}

bool Board::Action::move_ship(const Point &ship_center, const Point &destination) {
    return board_->move_ship(ship_center,destination);
}
