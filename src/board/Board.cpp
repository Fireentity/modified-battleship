#include <numeric>
#include "board/Board.h"
//Ship viene inclusa soltanto nel file .cpp per risolvere la dipendenza circolare
#include "ship/Ship.h"
#include "../Utilities.hpp"

/**
 * Si è preferito utilizzare delle stringhe pensando che con un sistema migliore queste possano essere lette
 * da un file di configurazione così da creare un sistema di localizzazione per i messaggi in output del programma.
 * Non potendo usare file esterni (non c'è scritto nelle specifiche del progetto) abbiamo risolto il problema così
 */
const std::string Board::numbers = "\t  %0%   %1%   %2%   %3%   %4%   %5%   %6%   %7%   %8%  %9%  %10%  %11%  \t\t";
const std::string Board::columns = "%12%\t| %0% | %1% | %2% | %3% | %4% | %5% | %6% | %7% | %8% | %9% | %10% | %11% |\t\t";
const std::string Board::separator = "\t" + utils::repeat("+---", Board::width) + "+\t\t";

Board::Board() {
    for (int i = 0 ;i < Board::height; i++) {
        for (int j = 0; j < Board::width; j++) {
            board_[i][j] = BoardSlot{Point{j+1, i+1}};
        }
    }
}

bool Board::is_out(unsigned int x, unsigned int y) {
    return x == 0 || y == 0 || x > Board::width || y > Board::height;
}

bool Board::is_out(const Point &point) {
    return is_out(point.get_x(), point.get_y());
}

const BoardSlot &Board::at(unsigned int x, unsigned int y) const {
    if (is_out(x, y)) {
        throw std::invalid_argument("Position out of bounds");
    }
    //Le coordinate sono invertite perché si usano i normali assi cartesiani e non le coordinate delle matrici
    return this->board_[y - 1][x - 1];
}

const BoardSlot &Board::at(const Point &point) const {
    return at(point.get_x(), point.get_y());
}

BoardSlot &Board::get_slot(const Point &point) {
    if (is_out(point)) {
        throw std::invalid_argument("Position out of bounds");
    }
    return board_[point.get_y() - 1][point.get_x() - 1];
}

BoardSlot &Board::get_slot(unsigned int x, unsigned int y) {
    if (is_out(x, y)) {
        throw std::invalid_argument("Position out of bounds");
    }
    return board_[y - 1][x - 1];
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
        this->board_[piece.get_position().get_y() - 1][piece.get_position().get_x() - 1].set_ship(ship);
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

    ship->set_center(destination);

    return true;
}

const std::vector<std::shared_ptr<Ship>> &Board::get_ships() const {
    return ships_;
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

void Board::remove_ship(const Point &point) {
    std::shared_ptr<Ship> ship = get_slot(point).get_ship();
    ship->for_each_piece([this](ShipPiece &piece) {
        get_slot(piece.get_position()).remove_ship();
    });
    ships_.erase(std::remove(ships_.begin(), ships_.end(), ship), ships_.end());
}

bool Board::has_ships() const {
    return !ships_.empty();
}

std::string Board::to_string() const {
    std::stringstream ss{""};
    int numbers_to_print[width];
    char chars_to_print[width+1];
    std::iota(numbers_to_print, numbers_to_print + width, 1);

    ss << utils::format(numbers, numbers_to_print) << utils::format(numbers, numbers_to_print) << std::endl << separator
       << separator << std::endl;

    for (int i = 0; i < Board::height; i++) {
        //La lettera che indica la riga
        chars_to_print[12] = utils::number_to_letter(i + 1);

        //Inserisce nell'array di caratteri il contenuto della board
        std::transform(board_[i], board_[i] + width, chars_to_print, [](const BoardSlot &slot) {
            return slot.get_defence_char();
        });

        //Sostituisco i placeholder nella stringa con il contenuto della riga della board
        ss << utils::format(columns, chars_to_print);

        //Inserisce nell'array di caratteri il contenuto della board
        std::transform(board_[i], board_[i] + width, chars_to_print, [](const BoardSlot &slot) {
            return slot.get_attack_char();
        });

        //Sostituisco i placeholder nella stringa con il contenuto della riga della board
        ss << utils::format(columns, chars_to_print) << std::endl << separator << separator << std::endl;
    }

    ss << "\t\t\t  " << "Griglia di difesa" << "\t\t\t\t\t\t " << "Griglia di attacco" << std::endl;

    return ss.str();
}

Board::Action::Action(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board)
        : board_{board}, enemy_board_{enemy_board} {
}

BoardSlot &Board::Action::get_slot(const Point &point) {
    return board_.lock()->get_slot(point);
}

BoardSlot &Board::Action::get_enemy_slot(const Point &point) {
    return enemy_board_.lock()->get_slot(point);
}

BoardSlot &Board::Action::get_enemy_slot(unsigned int x, unsigned int y) {
    return enemy_board_.lock()->get_slot(x, y);
}

bool Board::Action::move_ship(const Point &ship_center, const Point &destination) {
    return board_.lock()->move_ship(ship_center, destination);
}

BoardSlot &Board::Action::get_slot(unsigned int x, unsigned int y) {
    return board_.lock()->get_slot(x, y);
}

void Board::Action::remove_ship(const Point &point) {
    enemy_board_.lock()->remove_ship(point);
}