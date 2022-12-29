//
// Created by albyb on 29/12/2022.
//

#include "actions/RemoveHitMissAction.h"

bool RemoveMissAction0::do_action(const Point &target) {
        for(int i=0; i<Board::height; i++){
            for(int j=0; j<Board::width; j++){
                if(get_slot(i,j).get_state() == BoardSlot::HIT_MISSED){
                    get_slot(i,j).set_state(BoardSlot::EMPTY);
                }
            }
        }
        return true;
}
