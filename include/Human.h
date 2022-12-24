#ifndef HUMAN_H
#define HUMAN_H

#include "board/DefenceBoard.h"
#include "Player.h"
#include <iostream>
#include <regex>

class Human : public Player {
private:
    std::shared_ptr<DefenceBoard> defence_board;
public:
    //Le costanti vengono scritte in camel case invece che in maiuscolo per evitare di
    //avere conflitti con le macro. Tutti gli altri field sono scritti in snake case
    static const std::regex inputRegex;
    std::shared_ptr<DefenceBoard> place_ships_inside_board() override;
};

#endif //HUMAN_H
