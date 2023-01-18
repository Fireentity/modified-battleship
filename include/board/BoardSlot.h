//Lorenzo Croce 2034738

#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include <memory>
#include <ostream>
#include <functional>
#include "Point.h"

//Class forwarding per risolvere una dipendenza circolare
class Ship;

/**
 * Rappresenta uno slot della Board di gioco. Contiene un'associazione tra un pezzo della nave alle coordinate (x,y)
 * e lo stato dei colpi mandati a segno, mancati e i pezzi di nave rivelati .
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
     * @return ritorna un carattere che corrisponde al contenuto dello slot
     */
    char get_defence_char() const;

    /**
     * Metodo che permette di ottenere il contenuto dello slot che può essere vuoto oppure colpito, mancato o rivelato
     * @return ritorna un carattere che corrisponde allo stato dello slot
     */
    char get_attack_char() const;

    /**
     * Permette di modificare la ship contenuta nello slot
     * @param ship la ship passata come parametro
     */
    void set_ship(const std::shared_ptr<Ship> &ship);

    /**
     * Permette di accedere ad un'istanza di Ship senza che questa possa essere modificata
     * @return ritorna un'istanza di Ship
     */
    std::shared_ptr<const Ship> get_ship() const;

    /**
     * Permette di accedere ad un'istanza di Ship
     * @return
     */
    std::shared_ptr<Ship> get_ship();

    /**
     * Permette di modificare lo stato dello slot
     * @param state lo stato dello slot
     */
    void set_state(State state);

    /**
     * Permette di accedere allo stato corrente dello slot
     * @return ritorna un valore dell'enum State
     */
    State get_state() const;

    /**
     * Controlla se ha la nave
     * @return ritorna true se il puntatore alla nave è diverso da nullptr false altrimenti
     */
    bool has_ship() const;

    /**
     * Rimuove la nave dallo slot corrente
     */
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
