#ifndef MOVE_COMMAND
#define MOVE_COMMAND
#include "command.hpp"
class MoveCommand : public Command
{
public:
    MoveCommand(Registry *const, TaskManager *const, const CellAddress, const CellAddress);

    virtual void execute() final;

    virtual bool isInstruction() final;

    virtual String toString() final;

private:
    const CellAddress addressFrom;
    const CellAddress addressTo;
};
#endif