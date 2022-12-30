#ifndef SHIPACTIONCOMMAND_H
#define SHIPACTIONCOMMAND_H

#include "Command.h"
#include "board/Board.h"
#include "ship/Ship.h"
#include "Logger.h"
#include <regex>
#include <algorithm>

class ShipActionCommand : public Command {
private:
    const std::shared_ptr<Board> board_;
    Logger logger_;
    bool check_command(const std::string &argument) override;

public:
    //Le costanti vengono scritte in camel case invece che in maiuscolo per evitare di
    //avere conflitti con le macro. Tutti gli altri field sono scritti in snake case.
    //Le regex permettono di controllare che l'input dell'utente sia del formato corretto
    static const std::regex inputRegex;
    static const std::regex inputCharacterRegex;
    static const std::string commandFormat;

    explicit ShipActionCommand(const std::shared_ptr<Board> &board, const Logger &logger);

    bool execute(const std::string &argument) override;

    bool execute(const Point &ship_center, const Point &destination);
};

#endif //SHIPACTIONCOMMAND_H
