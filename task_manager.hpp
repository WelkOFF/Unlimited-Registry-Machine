#ifndef TASK_MANAGER
#define TASK_MANAGER
#include <iostream>
#include <vector>
#include "registry.hpp"
#include "executable.hpp"

using CommandIndex = unsigned long long;

class TaskManager
{
public:
    TaskManager(Registry *const);

    void addCommand(Pointer<Executable> newCommand);

    void executeLast();

    void removeLast();

    void loadFile(String filename);

    void executeCommands();

    void goToNextCommand();

    void goToCommand(longNumber commandPosition);

    void printCommands(std::ostream &out = std::cout) const;

private:
    std::vector<CommandIndex> instructionIndices;
    std::vector<Pointer<Executable>> loadedCommands;
    Registry *const registry;
    CommandIndex nextPosition{0};

    CommandIndex getCommandIndex(CommandIndex instructionIndex) const;
};
#endif