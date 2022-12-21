#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <stdexcept>
#include <functional>
#include "action/HitAction.h"
#include "action/MoveAndHealAction.h"
#include "action/MoveAndRevealAction.h"

//Rappresenta la classe che astrae un giocatore che sia umano o computer
class Player {
private:
    const std::shared_ptr<Board> board_;
    const std::shared_ptr<Board> enemy_board_;
public:

    static bool make_and_place_armoured_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                             const std::shared_ptr<Board> &enemy_board);
    static bool make_and_place_support_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                            const std::shared_ptr<Board> &enemy_board);
    static bool make_and_place_submarine(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                         const std::shared_ptr<Board> &enemy_board);
public:
    //Rappresenta il tipo di navi disponibili nella flotta di ciascun giocatore
    enum class Ships {
        ARMOURED,
        SUPPORT,
        SUBMARINE
    };
    //Permette di convertire in stringa ogni valore dell'enumerazione Ships
    static std::string to_string(Ships ship);
    //Rappresenta le navi disponibili nelle flotte dei due giocatori
    static const std::vector<Ships> available_ships;

    static bool instantiate_ship(Player::Ships ship_type, const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                 const std::shared_ptr<Board> &enemy_board);

    Player(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

    std::shared_ptr<Board> get_enemy_board() const;

    std::shared_ptr<Board> get_board() const;

    virtual void place_ships_inside_board() = 0;

    virtual void do_move(Board &enemy_board) = 0;

};

#endif //PLAYER_H
