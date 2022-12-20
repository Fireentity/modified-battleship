#ifndef BOARD_H
#define BOARD_H

#include <stdexcept>

template <class T, int N, int M>
class Board {
protected:
    T board_[N][M];
public:
    Board(const T &default_object) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                //Copia l'oggetto in tutti gli slot della board in modo
                //da inizializzare la tabella con il valore richiesto
                board_[i][j] = T{default_object};
            }
        }
    }

    const T &get_slot(int x, int y) {
        if(x > N || y > M || x < 0 || y < 0) {
            throw std::invalid_argument("Position out of bounds");
        }

        return this->board_[x][y];
    }

    void set_slot(int x, int y, const T &object) {
        if(x > N || y > M || x < 0 || y < 0) {
            throw std::invalid_argument("Position out of bounds");
        }

        board_[x][y] = T{object};
    }
};

#endif