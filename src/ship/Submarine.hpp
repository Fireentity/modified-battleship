#include <stdexcept>
#include "Point.h"
#include "ship/Ship.h"

class Submarine : public Ship {
private:
    static const unsigned short thickness = 1;
    static const unsigned short length = 1;
    static const unsigned short full_health = 1;
    static const unsigned short range = 2;
    static const char character = 'E';

public:

    Submarine(const Point &point, unsigned short width, unsigned short height,
              unsigned short health) : Ship(point, width, height, health) {

    }

    static Submarine initialize(unsigned int x, unsigned int y) {
        return Submarine{Point{x, y}, thickness, length, full_health};
    }

    char get_character() const override {
        return character;
    }

    template<int N, int M>
    void insert_into(const BoardPiece (&board)[N][M]) const {

        if (this->get_x() > N || this->get_y() > M) {
            throw std::invalid_argument("Position out of the board");
        }

        if (board[this->get_y()][this->get_x()].get_ship() != nullptr) {
            throw std::invalid_argument("Position already occupied by another ship");
        }

        board[this->get_y()][this->get_x()].get_ship() = std::make_shared<Ship>(this);
    }
};