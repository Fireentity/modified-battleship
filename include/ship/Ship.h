#ifndef SHIP_H
#define SHIP_H

#include <unordered_map>
#include <memory>
#include <vector>
#include <functional>
#include "Point.h"
#include "ShipPiece.h"
#include "board/Board.h"

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

    static const unsigned short armoured_ship_length;
    static const unsigned short support_ship_length;
    static const unsigned short submarine_length;
    static const int breadth;

    Ship(const Point &point, int width, int height, unsigned int size, int health, int max_health, const std::shared_ptr<Board::Action> &action);

    void for_each_piece(const std::function<void(ShipPiece&)> &on_iteration);

    bool do_action(const Point &target) const;

    unsigned int get_pieces_amount() const;

    void set_health(unsigned short health);

    int get_max_health() const;

    const Point &get_center();

    int get_health() const;
};

#endif //SHIP_H
