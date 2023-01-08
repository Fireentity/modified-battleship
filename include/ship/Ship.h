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

    //Rappresenta il tipo di navi disponibili nella flotta di ciascun giocatore
    enum Ships {
        ARMOURED,
        SUPPORT,
        SUBMARINE
    };

    static std::string to_string(Ship::Ships ship);

    Ship(const Point &top_left_corner, int width, int height, unsigned short pieces_amount,
         const std::shared_ptr<Board::Action> &action);

    Ship(Ship &ship) = delete;

    void for_each_piece(const std::function<void(ShipPiece &)> &on_iteration);

    const std::vector<ShipPiece> &get_pieces() const;

    char get_piece_character(unsigned int x, unsigned int y) const;

    virtual char get_damaged_character() const = 0;

    bool do_action(const Point &target) const;

    virtual char get_character() const = 0;

    unsigned int get_pieces_amount() const;

    void set_center(const Point &center);

    const Point &get_center() const;

    virtual Ships get_type() const = 0;

    int get_health() const;

    void hit(const Point &point);

    void heal();

    static bool instantiate_ship(Ship::Ships ship_type, const Point &top_left_corner, bool horizontal,
                                 const std::shared_ptr<Board> &board,const std::shared_ptr<Board> &enemy_board);

    static int get_length(Ship::Ships ship_type);

    Ship &operator=(const Ship &) = delete;

};

#endif //SHIP_H
