#ifndef SHIPCOMMAND_H
#define SHIPCOMMAND_H

#include "Command.h"
#include "board/Board.h"
#include "ship/Ship.h"
#include "logger/Logger.h"
#include <regex>
#include <algorithm>

class ShipCommand : public Command {

protected:
    bool check_command(const std::string &argument) override;

    const std::shared_ptr<Board> board_;
    std::shared_ptr<Logger> logger_;
public:
    //Le costanti vengono scritte in camel case invece che in maiuscolo per evitare di
    //avere conflitti con le macro. Tutti gli altri field sono scritti in snake case.
    //Le regex permettono di controllare che l'input dell'utente sia del formato corretto
    static const std::regex inputRegex;
    static const std::regex inputCharacterRegex;
    static const std::string commandFormat;

    ShipCommand(ShipCommand &) = delete;

    ShipCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Logger> &logger);

    bool execute(const std::string &argument) override;

    bool execute(const Point &first_point, const Point &second_point);

    /**
     * Metodo virtuale usato
     * @param first_point
     * @param second_point
     * @return
     */
    virtual bool execute_action(const Point &first_point, const Point &second_point) = 0;

    ShipCommand &operator=(ShipCommand &) = delete;
};

#endif //SHIPCOMMAND_H
