#include "board/AttackBoard.h"

const char AttackBoard::empty = ' ';
const char AttackBoard::miss = 'O';
const char AttackBoard::hit = 'X';
const char AttackBoard::revealed = 'Y';

AttackBoard::AttackBoard() : Board{empty} {

}
