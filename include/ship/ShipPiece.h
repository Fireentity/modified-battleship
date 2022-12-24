#ifndef SHIPPIECE_H
#define SHIPPIECE_H

#include "Point.h"
#include "board/DefenceBoard.h"

//Rappresenta un pezzo di nave nella scacchiera.
//Questa classe è stata pensata per semplificare i movimenti delle navi nella scacchiera. Le traslazioni infatti
//sono calcolate sulla base delle coordinate dei singoli pezzi. Anche se non richieso questa classe permette
//d'implementare barche di qualsiasi forma
class ShipPiece {
private:
    //Vengono utilizzati shared_ptr per risolvere il problema dell'ownership. In questo modo defence_board_ e ship_
    //verranno cancellate sono quando non ci saranno più shared_ptr correlati a queste due istanze
    std::shared_ptr<DefenceBoard> defence_board_;
    std::shared_ptr<Ship> ship_;
    Point position_;
    bool hit_ = false;
public:

    ShipPiece(const Point &, const std::shared_ptr<DefenceBoard> &, const std::shared_ptr<Ship> &);

    ShipPiece();

    std::shared_ptr<Ship> get_ship();

    const Point &get_position();

    bool is_valid_position(int x, int y);

    void move_to(int x, int y);

    void move_to(const Point &);

    bool is_hit();

    void hit();
};

#endif //SHIPPIECE_H
