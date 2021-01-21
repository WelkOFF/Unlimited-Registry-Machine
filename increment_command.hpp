#ifndef INCREMENT_COMMAND
#define INCREMENT_COMMAND
#include "command.hpp"
class IncrementCommand : public Command
{
public:
    IncrementCommand(Registry *const, TaskManager *const, const CellAddress);

    virtual void execute() final;

    virtual bool isInstruction() final;

    virtual String toString() final;

private:
    const CellAddress address;
};
#endif