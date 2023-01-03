#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <stdexcept>
#include <functional>
#include <iostream>
#include "ship/Armoured.h"
#include "ship/Supporter.h"
#include "ship/Submarine.h"
#include "commands/Command.h"

//Rappresenta la classe che astrae un giocatore umano o computer
class Player {
protected:
    std::vector<std::shared_ptr<Command>> commands_;
    const std::shared_ptr<Board> board_;
    const std::shared_ptr<Board> enemy_board_;
public:
    Player(Player &) = delete;

    Player(const std::shared_ptr<Board> &board,const std::shared_ptr<Board> &enemy_board);

    std::shared_ptr<const Board> get_board() const;

    virtual void place_ships_inside_board() = 0;

    virtual void do_move() = 0;

    void register_command(const std::shared_ptr<Command> &command);

    bool dispatch_command(const std::string &command);

    Player &operator=(const Player &) = delete;
};

#endif //PLAYER_H
