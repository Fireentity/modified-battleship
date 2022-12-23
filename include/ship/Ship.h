#ifndef SHIP_H
#define SHIP_H

#include <unordered_map>
#include <memory>
#include "Point.h"

//Viene risolta una dipendenza circolare usando il class forwarding
class DefenceBoard;

//La classe Ship rappresenta in modo astratto una nave all'interno. Viene implementata ed estesa per aggiungere
//ulteriori funzionalità
class Ship {
protected:
    Point position_;
    std::shared_ptr<DefenceBoard> defence_board_;
    unsigned short health_;
    const unsigned short width_ = 1;
    const unsigned short height_ = 1;
    const unsigned short max_health_;

public:

    Ship(const Point &point, unsigned short width, unsigned short height, unsigned short health, unsigned short max_health,
         const std::shared_ptr<DefenceBoard> &defence_board);

    int get_center_x() const;

    int get_center_y() const;

    unsigned short get_width() const;

    unsigned short get_height() const;

    unsigned short get_health() const;

    unsigned short get_max_health() const;

    void set_health(unsigned short health);

    virtual bool do_action(int x, int y) = 0;

    virtual char get_character() const = 0;

    virtual char get_damaged_character() const = 0;

    virtual void move(int x, int y) = 0;

    virtual bool is_valid_position(int x, int y) = 0;

    virtual bool place() = 0;
};

#endif //SHIP_H
