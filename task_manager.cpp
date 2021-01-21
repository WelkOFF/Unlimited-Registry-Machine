#include <iostream>
#include <fstream>
#include "command_parser.hpp"
#include "task_manager.hpp"
TaskManager::TaskManager(Registry *const newRegistry)
    : registry(newRegistry) {}

//Adds a new command/instruction to the end of the currently loaded program

void TaskManager::addCommand(Pointer<Executable> newCommand)
{
    if (newCommand->isInstruction())
    {
        instructionIndices.push_back(loadedCommands.size());
    }

    loadedCommands.push_back(Pointer<Executable>(std::move(newCommand)));
}

//Executes the last added command/instruction
void TaskManager::executeLast()
{
    loadedCommands[loadedCommands.size() - 1]->execute();
}

//Removes the last added command/instruction
void TaskManager::removeLast()
{
    loadedCommands.pop_back();
}

void TaskManager::loadFile(String filename)
{
    String line;
    std::ifstream inputFile(filename);
    instructionIndices.clear();
    loadedCommands.clear();

    while (std::getline(inputFile, line))
    {
        CommandParser parser(registry, this);
        try
        {
            Pointer<Executable> cmd = parser.parseCommand(line);

            this->addCommand(std::move(cmd));
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

//Execute the loaded program
void TaskManager::executeCommands()
{
    nextPosition = 0;
    for (; nextPosition < loadedCommands.size();)
    {
        loadedCommands[nextPosition]->execute();
    }
}

//Skip to the execution of the next command/instruction
void TaskManager::goToNextCommand()
{
    nextPosition++;
}

//Go to the execution of the n-th instruction
void TaskManager::goToCommand(longNumber commandPosition)
{
    nextPosition = getCommandIndex(commandPosition);
}

//Print the code of the current program
void TaskManager::printCommands(std::ostream &out) const
{
    for (size_t i = 0; i < loadedCommands.size(); ++i)
    {
        out << loadedCommands[i]->toString() << std::endl;
    }
}

//Return the line of the instruction with index instructionIndex
CommandIndex TaskManager::getCommandIndex(CommandIndex instructionIndex) const
{
    if (instructionIndices.size() <= instructionIndex)
    {
        return instructionIndices[instructionIndices.size() - 1] + 1;
    }
    else
    {
        return instructionIndices[instructionIndex];
    }
}
