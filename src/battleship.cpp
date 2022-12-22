#include <iostream>
#include "ship/Supporter.h"

int main () {
    std::vector<std::shared_ptr<Ship>> ships = std::vector<std::shared_ptr<Ship>>{};
    ships.push_back(std::make_shared<Supporter>(1,1,true));
    ships.push_back(std::make_shared<Supporter>(1,3,true));
    DefenceBoard defenceBoard{ships};
    std::cout<<defenceBoard;
}