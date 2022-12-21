#ifndef SHIP_H
#define SHIP_H

#include <unordered_map>
#include <memory>
#include "Point.h"

//Viene risolta una dipendenza circolare usando il class forwarding
class Board;

//La classe Ship rappresenta in modo astratto una nave all'interno. Viene implementata ed estesa per aggiungere
//ulteriori funzionalità
class Ship {
protected:
    Point position_;
    //Viene utilizzato uno shared_ptr per evitare il problema dell'ownership di board_
    std::shared_ptr<Board> defence_board_;
    int health_;
    const int width_ = 1;
    const int height_ = 1;
    const int max_health_;

public:

    //Vengono utilizzati degli short in quanto si pensa che non ci saranno dimensioni di barche che possano superare
    //il massimo numero rappresentato da un unsigned short
    //Gli shared_ptr sono passati come reference costanti per evitare di fare copie inutili. Mentre sono passati per
    //valore se ritornati dai metodi
    Ship(const Point &point, int width, int height, int health, int max_health,
         const std::shared_ptr<Board> &defence_board);

    int get_center_x() const;

    int get_center_y() const;

    unsigned short get_health() const;

    unsigned short get_max_health() const;

    void set_health(unsigned short health);

    virtual bool do_action(const Point &target, Board &enemy_board) = 0;

    virtual char get_character() const = 0;

    virtual char get_damaged_character() const = 0;

    virtual void move(const Point &destination) = 0;

    virtual bool is_valid_position(const Point &point) = 0;
};

#endif //SHIP_H
