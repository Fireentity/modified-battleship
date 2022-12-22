#ifndef BOARD_H
#define BOARD_H

#include <stdexcept>

template<class T, int N, int M>
class Board {
private:
    T board_[N][M];
    const int height = N;
    const int width = M;
public:

    static const std::string separator;
    static const std::string space;

    explicit Board(const T &default_object) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //Copia l'oggetto in tutti gli slot della board in modo
                //da inizializzare la tabella con il valore richiesto
                board_[i][j] = T{default_object};
            }
        }
    }

    int get_width() const {
        return width;
    }

    int get_height() const {
        return height;
    }

    const T &get_slot(unsigned int x, unsigned int y) const {
        if (x > N || y > M) {
            throw std::invalid_argument("Position out of bounds");
        }

        return this->board_[x][y];
    }

    void set_slot(unsigned int i, unsigned int j, const T &object) {
        if (j > N || i > M) {
            throw std::invalid_argument("Position out of bounds");
        }

        board_[i][j] = T{object};
    }
};

template<class T, int N, int M>
const std::string Board<T,N,M>::separator = "| ";

template<class T, int N, int M>
const std::string Board<T,N,M>::space = " ";

//TODO fix this method
template<class T, int N, int M>
std::ostream &operator<<(std::ostream &os, const Board<T, N, M> &board) {
    os << "\t";
    for (int i = 0; i < board.get_width(); i++) {
        os << "  " << i << " ";
    }
    os << std::endl << "\t";
    for(int j = 0; j < M; j++) {
        os << "+---";
    }
    os << "+" << std::endl;
    for (int i = 0; i < board.get_height(); i++) {
        os << i << "\t";
        for (int j = 0; j < board.get_width(); j++) {
            os << "| " << board.get_slot(i, j) << " " ;
        }
        os << "| " << std::endl << "\t";
        for(int j = 0; j < M; j++) {
            os << "+---";
        }
        os << "+" << std::endl;
    }
    return os;
}

#endif
