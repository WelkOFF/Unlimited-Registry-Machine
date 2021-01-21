#ifndef COPY_COMMAND
#define COPY_COMMAND
#include "command.hpp"
class CopyCommand : public Command
{
public:
    CopyCommand(Registry *const, TaskManager *const, const CellAddress, const CellAddress, const longNumber);

    virtual void execute() final;

    virtual String toString() final;

private:
    const CellAddress addressFrom;
    const CellAddress addressTo;
    const longNumber count;
};
#endif