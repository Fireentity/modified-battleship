#include "board/Board.h"
//Ship viene inclusa soltanto nel file .cpp per risolvere la dipendenza circolare
#include "ship/Ship.h"

/**
 *
 * @param x ascissa del punto da controllare
 * @param y ordinata del punto da controllare
 * Le coordinate partono da 1 fino agli estremi della tabella
 * @return vero se il punto è fuori dalla tabella, falso altrimenti
 */
bool Board::is_out(unsigned int x, unsigned int y) {
    return x == 0 || y==0 || x > Board::width || y > Board::height;
}

bool Board::is_out(const Point &point) {
    return is_out(point.get_x(), point.get_y());
}

const BoardSlot &Board::at(unsigned int x, unsigned int y) const {
    if (is_out(x, y)) {
        throw std::invalid_argument("Position out of bounds");
    }
    //Le coordinate sono invertite perché si usano i normali assi cartesiani e non le coordinate delle matrici
    return this->board_[y-1][x-1];
}

const BoardSlot &Board::at(const Point &point) const {
    return at(point.get_x(), point.get_y());
}

BoardSlot &Board::get_slot(const Point &point) {
    if (is_out(point)) {
        throw std::invalid_argument("Position out of bounds");
    }
    return board_[point.get_y()-1][point.get_x()-1];
}

BoardSlot &Board::get_slot(unsigned int x, unsigned int y) {
    if (is_out(x, y)) {
        throw std::invalid_argument("Position out of bounds");
    }
    return board_[y-1][x-1];
}

bool Board::insert_ship(const std::shared_ptr<Ship> &ship) {
    bool unable_to_place = std::any_of(ship->get_pieces().begin(), ship->get_pieces().end(),
                                       [this](const ShipPiece &piece) {
                                           return Board::is_out(piece.get_position()) ||
                                                  at(piece.get_position()).has_ship();
                                       });
    if (unable_to_place) {
        return false;
    }
    std::for_each(ship->get_pieces().begin(), ship->get_pieces().end(), [this, ship](const ShipPiece &piece) {
        this->board_[piece.get_position().get_y()-1][piece.get_position().get_x()-1].set_ship(ship);
    });
    ships_.push_back(ship);
    return true;
}

bool Board::move_ship(const Point &ship_center, const Point &destination) {
    //Le coordinate vengono invertite perché si è deciso di usare come riferimento le ascisse e le ordinate
    //di un piano cartesiano che sono invertite rispetto ad una matrice
    BoardSlot &slot = get_slot(ship_center);
    //Controlliamo ship_center sia effettivamente il centro della nave da spostare
    std::shared_ptr<Ship> ship = slot.get_ship();
    if (ship->get_center() != ship_center) {
        return false;
    }

    Point translation = destination - ship_center;

    std::vector<Point> positions{ship->get_pieces_amount()};

    auto iter = positions.begin();

    slot.get_ship()->for_each_piece([&iter, translation](ShipPiece &piece) {
        (*iter) = piece.get_position() + translation;
        iter++;
    });

    //Controllo che non ci siano altre navi nella destinazione
    //Se c'è una nave controllo che non sia quella che sto spostando
    bool cannot_move = std::any_of(positions.begin(), positions.end(), [this, ship](const Point &position) {
        return Board::is_out(position) ||
               (get_slot(position).get_ship() != nullptr && get_slot(position).get_ship() != ship);
    });

    if (cannot_move) {
        return false;
    }

    iter = positions.begin();
    slot.get_ship()->for_each_piece([&iter, this, ship](ShipPiece &piece) {

        Point piece_position = piece.get_position();
        piece.move_to((*iter));
        get_slot(piece_position).remove_ship();
        get_slot(*iter).set_ship(ship);
        iter++;
    });

    return true;
}

const std::vector<std::shared_ptr<Ship>> &Board::get_ships() const {
    return ships_;
}


//TODO remove hardcoded chars
std::string Board::number_to_letter(int n) {
    char letter = 'A' + (n - 1);
    if (letter >= 'J') {
        letter += 2;
    }
    return std::string{letter};
}

void Board::remove_state(BoardSlot::State state) {
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            if (get_slot(i, j).get_state() == state) {
                get_slot(i, j).set_state(BoardSlot::EMPTY);
            }
        }
    }
}

void Board::print() const {


    std::cout << "\t  ";
    for (int i = 0; i < Board::width; i++) {
        if (i < 10) {
            std::cout << "  " + std::to_string(i + 1) + " ";
        } else {
            std::cout << " " + std::to_string(i + 1) + " ";
        }
    }

    std::cout << "\t\t  ";
    for (int i = 0; i < Board::width; i++) {
        if (i < 10) {
            std::cout << "  " + std::to_string(i + 1) + " ";
        } else {
            std::cout << " " + std::to_string(i + 1) + " ";
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < Board::height; i++) {

        std::cout << "\t  ";

        for (int j = 0; j < 2 * Board::width; j++) {
            std::cout << "+---";
            if ((j + 1) % Board::width == 0 && j != 0) {
                std::cout << "+\t\t  ";
            }
        }

        std::cout << std::endl;

        std::cout << "\t"<< number_to_letter(i + 1)<<" " ;

        for (int j = 0; j < 2*Board::width; j++) {
            if(j<Board::width){
                std::cout << "| " << at(j+1, i+1).get_piece(j+1, i+1) << " ";
            } else {
                if(j==Board::width){
                    std::cout << number_to_letter(i + 1)<<" ";
                }
                std::cout << "| " << BoardSlot::to_character(at(j+1-Board::width, i+1).get_state()) << " ";
            }
            if ((j + 1) % Board::width == 0 && j != 0) {
                std::cout << "|\t\t";
            }
        }
        std::cout<<std::endl;
    }

    std::cout << "\t  ";

    for (int j = 0; j < 2*Board::width; j++) {
        std::cout << "+---";
        if ((j + 1) % Board::width == 0 && j != 0) {
            std::cout << "+\t\t  ";
        }
    }
    std::cout << std::endl;
    std::cout<<"\t\t\t  "<<"Griglia di difesa"<<"\t\t\t\t\t\t "<<"Griglia di attacco"<<std::endl;

}

Board::Action::Action(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board) : board_{board},
                                                                                                        enemy_board_{
                                                                                                                enemy_board} {
}

BoardSlot &Board::Action::get_slot(const Point &point) {
    return board_->get_slot(point);
}

BoardSlot &Board::Action::get_enemy_slot(const Point &point) {
    return enemy_board_->get_slot(point);
}

BoardSlot &Board::Action::get_enemy_slot(unsigned int x, unsigned int y) {
    return enemy_board_->get_slot(x, y);
}

bool Board::Action::move_ship(const Point &ship_center, const Point &destination) {
    return board_->move_ship(ship_center, destination);
}

BoardSlot &Board::Action::get_slot(unsigned int x, unsigned int y) {
    return board_->get_slot(x, y);
}
