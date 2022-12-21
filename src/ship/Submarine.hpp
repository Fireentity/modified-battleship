#include <stdexcept>
#include "Submarine.cpp"

class Submarine : public Ship {
private:
    static const unsigned short range = 2;
    static const char character = 'E';
public:

    Submarine(const Point &point, unsigned short width, unsigned short height,
                         unsigned short health) : Ship(point, width, height, health) {

    }

    char get_character() const override {
        return character;
    }

    template<int N>
    void insert_into(const BoardPiece (&board)[N][N]) const {
        int dim = std::max(this->get_height(), this->get_width());

        for (int i = 0; i < dim; i++) {
            //Questa exception non dovrebbe mai essere lanciata salvo nel caso in cui il programmatore
            //usi male questa classe
            if (this->get_x() > N || this->get_y() > N) {
                throw std::invalid_argument("Position out of the board");
            }

            if (board[this->get_y()][this->get_x()].get_ship() != nullptr) {
                throw std::invalid_argument("Position already occupied by another ship");
            }
            board[this->get_y()][this->get_x()].get_ship() = std::make_shared<Ship>(this);
        }
    }
};