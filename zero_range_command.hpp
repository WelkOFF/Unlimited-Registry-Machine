#ifndef ZERO_RANGE_COMMAND
#define ZERO_RANGE_COMMAND
#include "command.hpp"
class ZeroRangeCommand : public Command
{
public:
    ZeroRangeCommand(Registry *const, TaskManager *const, const CellAddress, const CellAddress);

    virtual void execute() final;

    virtual String toString() final;

private:
    const CellAddress addressBegin;
    const CellAddress addressEnd;
};
#endif