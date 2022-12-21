#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <regex>
#include <ostream>
#include <memory>
#include "BoardSlot.h"

class Board {
public:
    //I field height e width sono dichiarati nell'header perché le dimensioni della
    //matrice devono essere note a compile time
    static const int height = 12;
    static const int width = 12;

    static bool is_out(unsigned int x, unsigned int y);

    static bool is_out(const Point &point);

    BoardSlot &get_slot(unsigned int x, unsigned int y);

    BoardSlot &get_slot(const Point &point);

    void set_slot(int i, int j, const BoardSlot &object);

private:
    BoardSlot board_[Board::width][Board::height];
};

#endif //DEFENCEBOARD_H