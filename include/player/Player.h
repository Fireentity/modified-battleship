#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <functional>
#include "ship/Ship.h"

//Rappresenta la classe che astrae un giocatore che sia umano o computer
class Player {
private:
     Board board_;
     std::shared_ptr<Board> enemy_board;
public:
    //Rappresenta il tipo di navi disponibili nella flotta di ciascun giocatore
    enum Ships {
        ARMOURED,
        SUPPORT,
        SUBMARINE
    };

    //Permette di convertire in stringa ogni valore dell'enumerazione Ships
    static std::string to_string(Ships ship);

    //Rappresenta le navi disponibili nelle flotte dei due giocatori
    static const std::vector<Ships> available_ships;
    //Viene usato un factory method design pattern implementato tramite un unordered_map per avere complessità temporale
    //O(1). Nella mappa a ogni tipo di nave corrisponde una funzione per creare il relativo oggetto. Si potrebbe
    //implementare la stessa cosa utilizzando una catena di if else ma sarebbe meno flessibile
    //Questa mappa è creata in modo statico
    static const std::unordered_map<Ships,std::function<std::shared_ptr<Ship>(Point,Point,std::shared_ptr<Board>)>> factory;

    virtual std::shared_ptr<Board> place_ships_inside_board() = 0;

    virtual void do_move(Board &enemy_board) = 0;

};

#endif //PLAYER_H
