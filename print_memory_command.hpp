#ifndef PRINT_MEMORY_COMMAND
#define PRINT_MEMORY_COMMAND
#include "command.hpp"
class PrintMemoryCommand : public Command
{
public:
    PrintMemoryCommand(Registry *const, TaskManager *const, const CellAddress, const CellAddress);

    virtual void execute() final;

    virtual String toString() final;

private:
    const CellAddress addressBegin;
    const CellAddress addressEnd;
};
#endif