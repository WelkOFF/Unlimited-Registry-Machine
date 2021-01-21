#ifndef JUMP_CONDITION_COMMAND
#define JUMP_CONDITION_COMMAND
#include "command.hpp"
class JumpCondtitionCommand : public Command
{
public:
    JumpCondtitionCommand(Registry *const, TaskManager *const, const CellAddress, const CellAddress, const longNumber);

    virtual void execute() final;

    virtual bool isInstruction() final;

    virtual String toString() final;

private:
    const CellAddress cellAddress1;
    const CellAddress cellAddress2;
    const longNumber nextCommandPosition;
};
#endif