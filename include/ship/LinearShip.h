#ifndef ORIENTABLESHIP_H
#define ORIENTABLESHIP_H

#include <algorithm>
#include <stdexcept>
#include "board/BoardPiece.h"
#include "board/DefenceBoard.h"

class LinearShip : public Ship {
private:
    bool horizontal_;
public:
    LinearShip(unsigned int x,
               unsigned int y,
               unsigned short width,
               unsigned short height,
               unsigned short health,
               bool horizontal);

    bool is_horizontal() const;

    void place(DefenceBoard &defence_board) const override;

    virtual std::shared_ptr<LinearShip> get_shared_ptr() const = 0;

};

#endif //ORIENTABLESHIP_H
