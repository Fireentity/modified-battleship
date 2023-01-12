#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include <memory>
#include <ostream>
#include <functional>
#include "Point.h"

//Class forwarding per risolvere una dipendenza circolare
class Ship;

/**
 * Rappresenta uno slot della Board di gioco. Contiene un'associazione tra un pezzo della nave alle coordinate (x_,y_)
 * e lo stato di ciò che vede il giocatore avversario.
 * Si è preferito creare una sola Board per evitare di dover aggiornare oggetti in parallelo.
 */
class BoardSlot {

public:

    enum State {
        HIT,
        HIT_MISSED,
        REVEALED,
        EMPTY
    };

    BoardSlot();

    /**
     *
     * @param point il punto della board in cui si trova lo slot
     */
    explicit BoardSlot(const Point &point);

    /**
     * Associa ad ogni stato dello slot un carattere preciso. Poteva essere implementato anche con una mappa statica
     * e avrebbe avuto complessità O(1) ma lo si è ritenuto inutile
     * @param state lo stato di cui ottenere il carattere
     * @return ritorna il carattere associato allo stato dato in input
     */
    static char to_character(State state);

    /**
     * Metodo che permette di ottenere il contenuto dello slot che può essere vuoto oppure contenere una nave
     * @return un carattere che corrisponde al contenuto dello slot
     */
    char get_defence_char() const;

    /**
     * Metodo che permette di ottenere il contenuto dello slot che può essere vuoto oppure colpito, mancato o rivelato
     * @return un carattere che corrisponde allo stato dello slot
     */
    char get_attack_char() const;

    void set_ship(const std::shared_ptr<Ship> &ship);

    //Permette di accedere ad un'istanza di Ship senza che questa possa essere modificata
    std::shared_ptr<const Ship> get_ship() const;

    std::shared_ptr<Ship> get_ship();

    void set_state(State state);

    State get_state() const;

    bool has_ship() const;

    void remove_ship();

//I field privati sono stati dichiarati sotto perché doveva essere prima definita l'enumerazione State
private:
    std::shared_ptr<Ship> ship_;
    //Anche se la posizione è un dato ridondante in quanto si trova già nella matrice è comunque più comodo e veloce
    //averne una copia nello slot. Non ci sono problemi di anomalie di aggiornamento o simili in quanto questo field non
    //può essere modificato una volta inizializzato. Inoltre è la board stessa che implementa il codice per evitare
    //che il suo lo stato interno e dello slot differiscano
    Point position_;
    State state_;
};

#endif //BOARDPIECE_H
