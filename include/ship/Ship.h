#ifndef SHIP_H
#define SHIP_H

#include <memory>
#include <vector>
#include "Point.h"
#include "ShipPiece.h"
#include "board/Board.h"

class Ship {
private:
    const unsigned int pieces_amount_ = 1;
    const int max_health_;
    std::shared_ptr<Board::Action> action_;
    std::vector<ShipPiece> pieces_;
    Point center_;
    int health_;

public:

    /**
     *
     * @param top_left_corner il punto in alto a sinistra di una nave di qualsiasi forma
     * @param width la larghezza della nave
     * @param height l'altezza della nave
     * @param pieces_amount il numero di pezzi della nave
     * @param action l'azione che può eseguire la nave
     */
    Ship(const Point &top_left_corner, int width, int height, unsigned short pieces_amount,
         const std::shared_ptr<Board::Action> &action);

    Ship(Ship &ship) = delete;

    Ship &operator=(const Ship &) = delete;

    /**
     * Metodo che permette di accedere e modificare i pezzi che compongono la nave
     * @return ritorna una reference al vettore contente i pezzi che compongono la nave
     */
    std::vector<ShipPiece> &get_pieces();

    /**
     * Metodo che permette di ottenere il carattere dei pezzi di nave quando sono danneggiati.
     * Il metodo è virtuale perché l'alternativa sarebbe stata quella di mettere un field che rappresenta
     * il carattere dei pezzi della nave danneggiati. Siccome navi dello stesso tipo hanno carattere uguale si è preferito usare
     * un field statico all'interno delle implementazioni di Ship.
     * @return ritorna il carattere dei pezzi di nave quando sono danneggiati
     */
    virtual char get_damaged_character() const = 0;

    /**
     * Metodo che permette di ottenere il carattere dei pezzi di nave.
     * Il metodo è virtuale perché l'alternativa sarebbe stata quella di mettere un field che rappresenta
     * il carattere dei pezzi della nave. Siccome navi dello stesso tipo hanno carattere uguale si è preferito usare
     * un field statico all'interno delle implementazioni di Ship.
     * @return ritorna il carattere dei pezzi di nave quando sono danneggiati
     */
    virtual char get_character() const = 0;

    /**
     * Metodo che permette di ottenere il carattere associato ad un pezzo della nave date
     * le coordinate cartesiane
     * @param x ascissa del pezzo di nave
     * @param y ordinata del pezzo della nave
     * @return ritorna il carattere associato al pezzo di nave
     */
    char get_piece_character(unsigned int x, unsigned int y) const;

    /**
     * Metodo che permette di ottenere il carattere associato ad un pezzo della nave dato il punto
     * del pezzo di nave
     * @param position la posizione del pezzo di nave di cui ottenere il carattere
     * @return ritorna il carattere ossiciato al pezzi di nave
     */
    char get_piece_character(const Point &position) const;

    /**
     * @param x ascissa del pezzo di nave
     * @param y ordinata del pezzo di nave
     * @return ritorna una reference costante al pezzo di nave
     */
    ShipPiece& get_piece(unsigned int x, unsigned int y);

    /**
     *
     * @return ritorna il numero di pezzi di cui è composta la nave
     */
    unsigned int get_pieces_amount() const;

    /**
     *
     * @param center il nuovo centro della nave
     */
    void set_center(const Point &center);

    /**
     *
     * @return una reference costante al centro della nave
     */
    const Point &get_center() const;

    /**
     *
     * @return la vita rimanente della nave
     */
    int get_health() const;

    /**
     * Metodo che permette di eseguire l'azione della nave
     * @param target il punto di target dell'azione
     * @return ritorna true se l'azione è stata eseguita con successo false altrimenti
     */
    bool do_action(const Point &target) const;

    /**
     * Permette di colpire la nave in un punto. Viene decrementata la vita e i pezzi vengono aggiornati
     * in modo che is_hit sia true
     * Lancia exception se non esiste un pezzo di nave alle coordinate del punto
     * @param point il punto in cui la nave viene colpita
     */
    void hit(const Point &point);

    /**
     * Ripristina la vita della nave al massimo e aggiorna lo stato interno dei singoli pezzi
     */
    void heal();
};

#endif //SHIP_H
