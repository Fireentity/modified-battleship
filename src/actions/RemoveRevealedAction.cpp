//
// Created by albyb on 28/12/2022.
//

#include "action/RemoveRevealedAction.h"

bool RemoveRevealedAction::do_action(const Point &target) {

    for(int i=0; i<Board::height; i++){
        for(int j=0; j<Board::width; j++){
            if(get_slot(i,j).get_state() == BoardSlot::REVEALED){
                get_slot(i,j).set_state(BoardSlot::EMPTY);
            }
        }
    }
    return false;
}
