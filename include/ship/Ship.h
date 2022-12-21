#ifndef SHIP_H
#define SHIP_H

#include <unordered_map>
#include <memory>
#include "Point.h"
#include "ShipPiece.h"

class Board;

class Ship {
protected:
    Point position_;
    std::shared_ptr<Board::Action> action;
    std::vector<ShipPiece> pieces_;
    int health_;
    const int width_ = 1;
    const int height_ = 1;
    const unsigned int pieces_amount_ = 1;
    const int max_health_;

public:

    Ship(const Point &point, int width, int height, unsigned int size, int health, int max_health, const std::shared_ptr<Board::Action> &action);

    void for_each_piece(const std::function<void(ShipPiece&)> &on_iteration);

    void set_health(unsigned short health);

    bool do_action(const Point &target);

    int get_max_health() const;

    const Point &get_center();

    unsigned int get_pieces_amount() const;

    int get_health() const;
};

#endif //SHIP_H
