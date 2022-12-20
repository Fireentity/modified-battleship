#include <stdexcept>
#include "Point.h"
#include "ship/Ship.h"

class Supporter : public Ship {
private:
    static const unsigned short range = 1;
    static const char character = 'S';
    static const unsigned short length = 3;
    static const unsigned short thickness = 1;
    static const unsigned short full_health = 3;

public:
    Supporter(const Point &point,
              unsigned short width,
              unsigned short height,
              unsigned short health) : Ship(point, width, height, health) {

    }

    static Supporter initialize(bool horizontal, unsigned int x, unsigned int y) {
        return Supporter{Point{x, y},
                         horizontal ? length : thickness,
                         horizontal ? thickness : length,
                         full_health};
    }

    char get_character() const override {
        return Supporter::character;
    }

    template<int N>
    void insert_into(const BoardPiece (&board)[N][N]) const {
        int dim = std::max(this->get_height(), this->get_width());

        for (int i = 0; i < dim; i++) {
            Point position = Point{this->get_x(), this->get_y() - (dim / 2) + i};
            //Questa exception non dovrebbe mai essere lanciata salvo nel caso in cui il programmatore
            //usi male questa classe
            if (position.x_ > N || position.y_ > N || position.x_ < 0 || position.y_ < 0) {
                throw std::invalid_argument("Position out of the board");
            }

            if (board[position.x_][position.y_].get_ship() != nullptr) {
                throw std::invalid_argument("Position already occupied by another ship");
            }
            board[position.x_][position.y_].get_ship() = std::make_shared<Ship>(this);
        }
    }
};


