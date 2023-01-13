#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <random>


/**
 * Questa classe serve per avere numeri più randomici della semplice funzione rand()
 * per evitare problemi di duplicazione nella generazione delle mosse tra le due AI
 */
class RandomNumber {
public:
    RandomNumber();

    int get_int(int lowest, int highest);

    /**
     * metodo che implementa un singleton design pattern.
     * La randomicità aumenta se viene usata sempre la stessa istanza di generator_ per le operazioni.
     * Infatti questo design pattern mi permette di accedere sempre alla medesima istanza di RandomNumber senza
     * l'ausilio di puntatori
     * @return un'istanza di RandomNumber
     */
    static RandomNumber &get_instance();

private:
    std::mt19937 generator_;
    static RandomNumber instance;
};

#endif //RANDOMNUMBER_H