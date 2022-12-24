#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <functional>
#include "ship/Ship.h"
#include "ship/ArmouredShip.h"
#include "ship/Submarine.h"
#include "ship/Supporter.h"

//Rappresenta la classe che astrae un giocatore che sia umano o computer
class Player {
public:
    //Rappresenta il tipo di navi disponibili nella flotta di ciascun giocatore
    enum Ships {
        ARMOURED,
        SUPPORT,
        SUBMARINE
    };

    //Rappresenta le navi disponibili nelle flotte dei due giocatori
    static const std::vector<Ships> available_ships;
    //È un design pattern comune per creare oggetti senza dover chiamare direttamente il costruttore della classe
    //È una mappa dove a ogni ship corrisponde una funzione per creare il relativo oggetto.
    //Questa mappa è creata in modo statico
    //Si preferisce un unordered_map per avere tempo di accesso O(1)
    static const std::unordered_map<Ships,std::function<std::shared_ptr<Ship>(int,int,bool,std::shared_ptr<DefenceBoard>)>> factory;
    virtual std::shared_ptr<DefenceBoard> place_ships_inside_board() = 0;

};

#endif //PLAYER_H
