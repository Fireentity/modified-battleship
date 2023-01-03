#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <regex>
#include <iostream>
#include <memory>
#include "Point.h"
#include "BoardSlot.h"

//La classe Board rappresenta la tabella di gioco e permette di modificare lo stato interno delle navi in modo sicuro
//senza che venga dato l'accesso all'esterno.
class Board {
public:
    //La classe Action rappresenta un'azione eseguibile da una nave sulla Board. Si è scelto di usare una nested class
    //in modo da non esporre metodi che possano cambiare lo stato interno delle navi all'esterno della board. La nested
    //class infatti permette di accedere ai metodi protected della Board
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
        Action(Action &) = delete;
        virtual bool do_action(const Point &ship_center, const Point &target) = 0;
        Action &operator=(const Action &) = delete;
    };


    static const int height = 12;
    static const int width = 12;

    static bool is_out(unsigned int x, unsigned int y);

    static bool is_out(const Point &point);

    const BoardSlot &at(unsigned int x, unsigned int y) const;

    const BoardSlot &at(const Point &point) const;

    const std::vector<std::shared_ptr<Ship>> &get_ships() const;

    void remove_state(BoardSlot::State state);

    void print_with_ships() const;

    void print_without_ships() const;

    //Viene creata una copia della nave così da impedire che lo stato interno della nave possa essere
    //modificato dall'esterno. Infatti non si possono ottenere le istanze di Ship contenute in Board
    bool insert_ship(const std::shared_ptr<Ship> &ship);

protected:
    bool move_ship(const Point &ship_center, const Point &destination);
    BoardSlot &get_slot(const Point &point);
    BoardSlot &get_slot(unsigned int x, unsigned int y);

private:
    BoardSlot board_[Board::height][Board::width];
    std::vector<std::shared_ptr<Ship>> ships_;

    static std::string number_to_letter(int n) ;
};

#endif //DEFENCEBOARD_H