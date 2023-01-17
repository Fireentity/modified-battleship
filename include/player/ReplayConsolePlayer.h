#ifndef REPLAYFILEPLAYER_H
#define REPLAYFILEPLAYER_H

#include "Player.h"
#include "logger/Logger.h"
#include "commands/ShipPlaceCommand.h"
#include "commands/ShipActionCommand.h"
#include "ReplayFilePlayer.h"

/**
 * Giocatore che esegue le mosse da un iteratore ad un vettore di stringhe
 */
class ReplayConsolePlayer : public ReplayFilePlayer {
public:
    /**
     *
     * @param board la board del giocatore
     * @param enemy_board la board dell'avversario
     * @param moves_logger il logger delle mosse eseguite da questo giocatore
     * @param info_logger il logger della defence board e attackboard
     * @param change_turn la funzione che viene eseguita quando correttamente un'azione
     * @param moves_iterator puntatore all'iteratore delle mosse
     * @param end l'ultimo elemento dell'iteratore delle mosse
     */
    ReplayConsolePlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                        const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &info_logger,
                        const std::string &name, const std::function<void()> &change_turn,
                        const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
                        const std::vector<std::string>::const_iterator &end);

    void do_move() override;
};


#endif //REPLAYFILEPLAYER_H
