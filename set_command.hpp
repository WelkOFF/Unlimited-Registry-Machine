#ifndef SET_COMMAND
#define SET_COMMAND
#include "command.hpp"
class SetCommand : public Command
{
public:
    SetCommand(Registry *const, TaskManager *const, const CellAddress, const CellAddress);

    virtual void execute() final;

    virtual String toString() final;

private:
    const CellAddress address;
    const CellValue value;
};
#endif