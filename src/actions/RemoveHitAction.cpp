

#include "actions/RemoveHitAction.h"

bool RemoveHitAction::do_action(const Point &point) {

    for(int i=0; i<Board::height; i++){
        for(int j=0; j<Board::width; j++){
            if(get_slot(i,j).get_state() == BoardSlot::HIT){
                get_slot(i,j).set_state(BoardSlot::EMPTY);
            }
        }
    }
    return true;
}

RemoveHitAction::RemoveHitAction(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemyBoard)
        : Action(board, enemyBoard) {

}

