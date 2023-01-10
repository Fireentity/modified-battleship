#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <regex>
#include <iostream>
#include <memory>
#include "Point.h"
#include "BoardSlot.h"

/**
 * Questa classe rappresenta la tabella di gioco e permette di modificare lo stato interno delle navi in modo sicuro
 * senza che venga dato l'accesso all'esterno. Anche se implementata come matrice si è preferito usare un sistema
 * di riferimento cartesiano
 */
class Board {
public:
    /**
     * La classe Action rappresenta un'azione eseguibile da una nave sulla Board. Si è scelto di usare una nested class
     * in modo da non esporre metodi che possano cambiare lo stato interno delle navi all'esterno della board. La nested
     * class infatti permette di accedere ai metodi protected della Board
     */
    class Action {
    private:
        /**
         * Vengono utilizzati dei weak_ptr per evitare memory leak. Se due oggetti contengono uno lo shared_ptr dell'altro
         * si crea un memory leak che può essere risolto solo tramite l'uso di weak_ptr.
         */
        std::weak_ptr<Board> board_;
        std::weak_ptr<Board> enemy_board_;
    protected:
        /**
         * Delegate per permettere alle classe derivate di Action di accedere al metodo Board#get_slot del field board_
         * @param point il punto dello slot
         * @return ritorna una reference ad un BoardSlot
         */
        BoardSlot &get_slot(const Point &point);

        /**
         * Delegate per permettere alle classe derivate di Action di accedere al metodo Board#get_slot del field board_
         * @param x ascissa dello slot
         * @param y ordinata dello slot
         * @return ritorna una reference ad un BoardSlot
         */
        BoardSlot &get_slot(unsigned int x, unsigned int y);

        /**
         * Delegate per permettere alle classe derivate di Action di accedere al metodo Board#get_slot del field enemy_board_
         * @param point il punto dello slot
         * @return ritorna una reference ad un BoardSlot
         */
        BoardSlot &get_enemy_slot(const Point &point);

        /**
         * Delegate per permettere alle classe derivate di Action di accedere al metodo Board#get_slot del field enemy_board_
         * @param x ascissa dello slot
         * @param y ordinata dello slot
         * @return ritorna una reference ad un BoardSlot
         */
        BoardSlot &get_enemy_slot(unsigned int x, unsigned int y);

        /**
         * Delegate per permettere alle classe derivate di Action di accedere al metodo Board#remove_ship del field enemy_board_
         * @param point il punto centrale della nave
         */
        void remove_ship(const Point &point);

        /**
         * Delegate per permettere alle classe derivate di Action di accedere al metodo Board#move_ship del field enemy_board_
         * @param ship_center il centro della nave da traslare
         * @param destination la destinazione della nave
         * @return ritorna false se la nave non si può spostare
         */
        bool move_ship(const Point &ship_center, const Point &destination);

    public:
        Action(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

        /**
         * Viene cancellato il costruttore di copia per evitare lo slicing
         */
        Action(Action &) = delete;

        /**
         * Esegue un'azione generica su una delle due board o su entrambe
         * @param ship_center il centro della nave che deve eseguire l'azione
         * @param target il destinatario dell'azione
         * @return true se l'azione è andata a buon file false altrimenti
         */
        virtual bool do_action(const Point &ship_center, const Point &target) = 0;

        /**
         * Viene cancellato l'operatore di assegnazione per evitare lo slicing
         */
        Action &operator=(const Action &) = delete;
    };


    static const int height = 12;
    static const int width = 12;

    /**
     * Metodo per controllare se il punto è o meno all'interno della board.
     * @param x ascissa del punto da controllare
     * @param y ordinata del punto da controllare
     * @return ritorna true se il punto è all'esterno della board
     */
    static bool is_out(unsigned int x, unsigned int y); //

    /**
     * Metodo per controllare se il punto è o meno all'interno della board.
     * @param point punto da controllare
     * @return ritorna true se il punto è all'esterno della board
     */
    static bool is_out(const Point &point); //

    /**
     * Metodo per ottenere una reference ad un BoardSlot. Questo metodo non permette di cambiare lo stato interno
     * della board
     * @param x ascissa dello slot
     * @param y ordinata dello slot
     * @return ritorna una const reference ad un BoardSlot
     */
    const BoardSlot &at(unsigned int x, unsigned int y) const; //

    /**
     * Metodo per ottenere una reference ad un BoardSlot. Questo metodo non permette di cambiare lo stato interno
     * della board
     * @param point punto dello slot
     * @return ritorna una const reference ad un BoardSlot
     */
    const BoardSlot &at(const Point &point) const; //

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

    //Viene creata una copia della nave così da impedire che lo stato interno della nave possa essere
    //modificato dall'esterno. Infatti non si possono ottenere le istanze di Ship contenute in Board
    bool insert_ship(const std::shared_ptr<Ship> &ship);

    /**
     * Metodo che controlla se sono rimaste delle navi corazzate nella board. Serve per controllare se la condizione
     * di vittoria è soddisfatta
     * @return
     */
    bool has_ships() const;

    //TODO metodo duplicato
    static std::string number_to_letter(int n);

protected:

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
std::ostream &operator<<(std::ostream &os, const Board &board);
#endif //DEFENCEBOARD_H