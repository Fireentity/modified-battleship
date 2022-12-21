#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <regex>
#include <ostream>
#include <memory>
#include "Point.h"
#include "BoardSlot.h"

class Board {
public:
    class Action {
    private:
        std::shared_ptr<Board> board_;
        std::shared_ptr<Board> enemy_board_;
    protected:
        //Vengono creati dei delegate per rendere disponibili i metodi di Board anche nelle possibili
        //implementazioni di Action
        BoardSlot &get_slot(const Point &point);
        BoardSlot &get_slot(unsigned int x, unsigned int y);
        BoardSlot &get_enemy_slot(const Point &point);
        BoardSlot &get_enemy_slot(unsigned int x, unsigned int y);
        bool move_ship(const Point &ship_center, const Point &destination);
    public:
        Action(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board);
        virtual bool do_action(const Point &target) = 0;

    };

    //I field height e width sono dichiarati nell'header perché le dimensioni della
    //matrice devono essere note a compile time
    static const int height = 12;
    static const int width = 12;

    static bool is_out(unsigned int x, unsigned int y);

    static bool is_out(const Point &point);

    const BoardSlot &at(unsigned int x, unsigned int y) const;

    const BoardSlot &at(const Point &point) const;

    const std::vector<std::shared_ptr<Ship>> &get_ships() const;

    //Viene creata una copia della nave così da impedire che lo stato interno della nave possa essere
    //modificato dall'esterno. Infatti non si possono ottenere le istanze di Ship contenute in Board
    bool insert_ship(Ship ship);

protected:
    bool move_ship(const Point &ship_center, const Point &destination);
    BoardSlot &get_slot(const Point &point);
    BoardSlot &get_slot(unsigned int x, unsigned int y);

private:
    BoardSlot board_[Board::width][Board::height];
    std::vector<std::shared_ptr<Ship>> ships_;
};

#endif //DEFENCEBOARD_H