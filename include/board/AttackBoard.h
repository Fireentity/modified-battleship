#ifndef ATTACKBOARD_H
#define ATTACKBOARD_H

class AttackBoard {
private:
    //TODO try to move in header file or else write a comment
    static const unsigned short dim = 12;
    static const char empty = ' ';
    char board_[dim][dim];
public:
    AttackBoard();

    void set_slot(int x, int y, char character);
};

#endif //ATTACKBOARD_H
