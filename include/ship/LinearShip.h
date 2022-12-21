#ifndef ORIENTABLESHIP_H
#define ORIENTABLESHIP_H

#include <algorithm>
#include <stdexcept>
#include <vector>
#include "ship/Ship.h"
#include "ShipPiece.h"

//Rappresenta una nave che può essere orientata sul piano della griglia di gioco
class LinearShip : public Ship {
protected:
    //Viene utilizzato un std::vector invece di un array perché non è nota la dimensione a compile time. Se si volesse
    //usare un array bisognerebbe rendere questa classe una classe template (sarebbe più difficile da gestire)
    std::vector<std::shared_ptr<ShipPiece>> pieces_;
public:
    LinearShip(const Point &center, int width, int height, int health, int max_health,
               const std::shared_ptr<Board> &defence_board);

    bool is_valid_position(const Point &point) override;

    void move(const Point &destination) override;
};

#endif //ORIENTABLESHIP_H
