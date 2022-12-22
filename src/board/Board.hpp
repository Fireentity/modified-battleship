#ifndef BOARD_H
#define BOARD_H

#include <stdexcept>

template <class T, int N, int M>
class Board {
private:
    T board_[N][M];
    const int height = N;
    const int width = M;
public:
    explicit Board(const T &default_object) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
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

    const T &get_slot(unsigned int x,unsigned int y) const {
        if(x > N || y > M) {
            throw std::invalid_argument("Position out of bounds");
        }

        return this->board_[x][y];
    }

    void set_slot(unsigned int x,unsigned int y, const T &object) {
        if(x > N || y > M) {
            throw std::invalid_argument("Position out of bounds");
        }

        board_[x][y] = T{object};
    }
};

#endif