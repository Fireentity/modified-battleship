//Lorenzo Croce 2034738

#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <regex>
#include <iostream>
#include <memory>
#include <numeric>
#include <array>
#include "Point.h"
#include "BoardSlot.h"

/**
 * Questa classe rappresenta la tabella di gioco e permette di modificare lo stato interno delle navi in modo sicuro
 * senza che venga dato l'accesso all'esterno. Anche se implementata come matrice si è preferito usare un sistema
 * di riferimento cartesiano.
 */
class Board {
public:

    static const std::string numbers;
    static const std::string columns;
    static const std::string separator;
    static const std::string tab;
    static constexpr int width = 12;
    static constexpr int height = 12;

    /**
     * Metodo per controllare se il punto è o meno all'interno della board.
     * @param x ascissa del punto da controllare
     * @param y ordinata del punto da controllare
     * @return ritorna true se il punto è all'esterno della board
     */
    static bool is_out(unsigned int x, unsigned int y);

    /**
     * Metodo per controllare se il punto è o meno all'interno della board.
     * @param point punto da controllare
     * @return ritorna true se il punto è all'esterno della board
     */
    static bool is_out(const Point &point);


    Board();

    /**
     * Metodo per ottenere una reference ad un BoardSlot. Questo metodo non permette di cambiare lo stato interno
     * della board
     * @param x ascissa dello slot
     * @param y ordinata dello slot
     * @return ritorna una const reference ad un BoardSlot
     */
    const BoardSlot &at(unsigned int x, unsigned int y) const;

    /**
     * Metodo per ottenere una reference ad un BoardSlot. Questo metodo non permette di cambiare lo stato interno
     * della board
     * @param point punto dello slot
     * @return ritorna una const reference ad un BoardSlot
     */
    const BoardSlot &at(const Point &point) const;

    /**
     * Metodo per ottenere una lista delle istanze delle navi presenti nella board
     * della board
     * @return ritorna una const reference ad un vettore di shared_ptr di Ship
     */
    const std::vector<std::shared_ptr<Ship>> &get_ships() const;

    /**
     * Metodo che permette di rimuovere lo stato salvato nei BoardSlot della board. Gli stati sono elencati
     * con un'apposita enumerazione in BoardSlot::State. Si è deciso di esporre questo metodo per evitare di aggiungere
     * ulteriore complessità al codice. Anche se modifica lo stato interno di Board non permette comunque di invalidarlo
     * @param state lo stato che deve essere cancellato da tutti gli slot della board
     */
    void remove_state(BoardSlot::State state);

    /**
     * Posiziona una nave nella board
     * @param ship il puntatore alla nave da posizionare
     * @return ritorna true se la nave è posizionata correttamente
     */
    bool insert_ship(const std::shared_ptr<Ship> &ship);

    /**
     * Metodo che controlla se sono rimaste delle navi corazzate nella board. Serve per controllare se la condizione
     * di vittoria è soddisfatta
     * @return true se rimangono navi nella board false altrimenti
     */
    bool has_ships() const;

    /**
     * Metodo per poter mandare in output il contenuto della board. Si è deciso di usare un metodo to_string invece
     * che l'overloading dell'operatore di output per evitare di scrivere codice duplicato.
     * Infatti l'operatore di output di ofstream non accetta ostream come parametro di input quindi è impossibile
     * fare: file_stream << board
     * @return la stringa contente la attackboard e la defenceboard
     */
    std::string to_string() const;

    /**
     * Permette di muovere una nave nella board. Implementa un sistema di spostamento tramite una traslazione che, quindi,
     * si adatta potenzialmente a navi di forme diverse. Essendo un algoritmo generico si è deciso di inserirlo in Board
     * invece che in Ship.
     * @param ship_center il centro della nave da traslare
     * @param destination la destinazione della nave
     * @return ritorna false se la nave non si può spostare
     */
    bool move_ship(const Point &ship_center, const Point &destination);

    /**
     * Metodo per ottenere una reference ad un BoardSlot. Questo metodo permette di cambiare lo stato interno
     * della board
     * @param x ascissa dello slot
     * @param y ordinata dello slot
     * @return ritorna una reference ad un BoardSlot
     */
    BoardSlot &get_slot(unsigned int x, unsigned int y);

    /**
     * Metodo per ottenere una reference ad un BoardSlot. Questo metodo permette di cambiare lo stato interno
     * della board
     * @param point punto dello slot
     * @return ritorna una reference ad un BoardSlot
     */
    BoardSlot &get_slot(const Point &point);

    /**
     * Permette di togliere una nave dalla matrice della board e dal vettore contenente tutte le navi
     * @param point il punto centrale della nave
     */
    void remove_ship(const Point &point);

private:
    BoardSlot board_[Board::height][Board::width];
    std::vector<std::shared_ptr<Ship>> ships_;

};
#endif //DEFENCEBOARD_H