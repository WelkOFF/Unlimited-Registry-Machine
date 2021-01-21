#ifndef COMMAND
#define COMMAND
#include "executable.hpp"
#include "registry.hpp"
#include "task_manager.hpp"

class Command : public Executable
{
public:
    Command() = default;

    Command(Registry *const newRegistry, TaskManager *const newTaskManager);

    virtual void execute() = 0;

    virtual String toString() = 0;

    virtual ~Command() = default;

protected:
    Registry *const registry{};
    TaskManager *const taskManager{};
};
#endif