#ifndef COMMAND_H
#define COMMAND_H


#include <string>

class Command {
protected:
    virtual bool check_command(const std::string &argument) =0;
public:
    bool dispatch(const std::string &input);
    virtual bool execute(const std::string &argument) =0;



};


#endif //COMMAND_H
