#ifndef SHIP_H
#define SHIP_H

#include <memory>
#include <vector>
#include "Point.h"
#include "ShipPiece.h"
#include "board/Board.h"

class Ship {
private:
    const unsigned int pieces_amount_ = 1;
    const int max_health_;
    std::shared_ptr<Board::Action> action_;
    std::vector<ShipPiece> pieces_;
    Point center_;
    int health_;

public:

    Ship(const Point &top_left_corner, int width, int height, unsigned short pieces_amount, const std::shared_ptr<Board::Action> &action);

    void for_each_piece(const std::function<void(ShipPiece&)> &on_iteration);

    virtual char get_damaged_character() const = 0;

    bool do_action(const Point &target) const;

    virtual char get_character() const = 0;

    unsigned int get_pieces_amount() const;

    void set_health(unsigned short health);

    int get_max_health() const;

    const Point &get_center();

    int get_health() const;
};

#endif //SHIP_H
