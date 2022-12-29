#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <stdexcept>
#include <functional>
#include <iostream>
#include "action/HitAction.h"
#include "action/MoveAndHealAction.h"
#include "action/MoveAndRevealAction.h"
#include "ship/ArmouredShip.h"
#include "ship/SupporterShip.h"
#include "ship/Submarine.h"

//Rappresenta la classe che astrae un giocatore umano o computer
class Player {
private:
    const std::shared_ptr<Board> board_;
    const std::shared_ptr<Board> enemy_board_;
public:
    static const int firstUpperCaseLetter;

    //Rappresenta le navi disponibili nelle flotte dei due giocatori
    static const std::vector<Ship::Ships> available_ships;

    Player(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

    std::shared_ptr<Board> get_enemy_board() const;

    std::shared_ptr<Board> get_board() const;

    virtual void place_ships_inside_board() = 0;

    virtual void do_move() = 0;
};

#endif //PLAYER_H
