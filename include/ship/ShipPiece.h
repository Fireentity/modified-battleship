#ifndef SHIPPIECE_H
#define SHIPPIECE_H

#include "Point.h"
#include "board/Board.h"

//Rappresenta un pezzo di nave nella scacchiera.
//Questa classe è stata pensata per semplificare i movimenti delle navi nella scacchiera. Le traslazioni infatti
//sono calcolate sulla base delle coordinate dei singoli pezzi. Anche se non richieso questa classe permette
//d'implementare barche di qualsiasi forma
class ShipPiece {
private:
    //Vengono utilizzati shared_ptr per risolvere il problema dell'ownership. In questo modo defence_board_ e ship_
    //verranno cancellate sono quando non ci saranno più shared_ptr correlati a queste due istanze
    std::shared_ptr<Board> defence_board_;
    std::shared_ptr<Ship> ship_;
    Point position_;
    bool hit_ = false;
public:

    ShipPiece(const Point &position);

    ShipPiece();

    void move_to(const Point &point);

    const Point &get_position() const;

    bool is_hit();

    void hit();
};

#endif //SHIPPIECE_H
