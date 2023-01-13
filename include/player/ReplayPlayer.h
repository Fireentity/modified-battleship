#ifndef REPLAYPLAYER_H
#define REPLAYPLAYER_H

#include <fstream>
#include <thread>
#include "ship/Armoured.h"
#include "ship/Supporter.h"
#include "board/Board.h"
#include "Player.h"
#include "commands/ShipPlaceCommand.h"
#include "commands/ShipActionCommand.h"

/**
 * Giocatore che esegue le mosse da un iteratore ad un vettore di stringhe
 */
class ReplayPlayer : public Player {
public:
    /**
     *
     * @param board la board del giocatore
     * @param enemy_board la board dell'avversario
     * @param moves_logger il logger delle mosse eseguite da questo giocatore
     * @param output_logger il logger della defence board e attackboard
     * @param change_turn la funzione che viene eseguita quando correttamente un'azione
     * @param moves_iterator puntatore all'iteratore delle mosse
     * @param end l'ultimo elemento dell'iteratore delle mosse
     */
    ReplayPlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                 const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &output_logger,
                 const std::function<void()> &change_turn,
                 const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
                 const std::vector<std::string>::const_iterator &end);

    void place_ships_inside_board() override;

    void do_move() override;

private:
    std::shared_ptr<std::vector<std::string>::const_iterator> moves_iterator_;
    const std::vector<std::string>::const_iterator end_iterator_;
    ShipPlaceCommand place_command_;
    std::shared_ptr<Logger> logger_;
};

#endif //REPLAYPLAYER_H
