#ifndef ZERO_COMMAND
#define ZERO_COMMAND
#include "command.hpp"
class ZeroCommand : public Command
{
public:
    ZeroCommand(Registry *const, TaskManager *const, const CellAddress);

    virtual void execute() final;

    virtual bool isInstruction() final;

    virtual String toString() final;

private:
    const CellAddress address;
};
#endif