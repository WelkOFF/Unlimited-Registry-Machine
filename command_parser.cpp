#include "command_parser.hpp"
#include "unknown_command.hpp"
#include "zero_command.hpp"
#include "increment_command.hpp"
#include "move_command.hpp"
#include "jump_command.hpp"
#include "jump_condition_command.hpp"
#include "zero_range_command.hpp"
#include "set_command.hpp"
#include "copy_command.hpp"
#include "print_memory_command.hpp"
#include "load_command.hpp"
#include "run_command.hpp"
#include "code_command.hpp"
#include "comment_command.hpp"

CommandParser::CommandParser(Registry *const newRegistry, TaskManager *const newTaskManager)
    : registry(newRegistry),
      taskManager{newTaskManager} {}

std::unique_ptr<Executable> CommandParser::parseCommand(String textCommand)
{
    std::istringstream inputStream(textCommand);
    String commandType;
    inputStream >> commandType;

    if (commandType.empty())
    {
        throw std::runtime_error("Please, input command.");
    }
    //1.1
    else if (commandType.compare("ZERO") == 0)
    {
        CellAddress address;
        inputStream >> address;
        return std::make_unique<ZeroCommand>(registry, taskManager, address);
    }
    //1.2
    else if (commandType.compare("INC") == 0)
    {
        CellAddress address;
        inputStream >> address;
        return std::make_unique<IncrementCommand>(registry, taskManager, address);
    }
    //1.3
    else if (commandType.compare("MOVE") == 0)
    {
        CellAddress addressFrom;
        CellAddress addressTo;
        inputStream >> addressFrom >> addressTo;
        return std::make_unique<MoveCommand>(registry, taskManager, addressFrom, addressTo);
    }
    //1.4,1.5
    else if (commandType.compare("JUMP") == 0)
    {
        longNumber arg1, arg2, arg3;
        inputStream >> arg1;
        if (inputStream >> arg2)
        {
            inputStream >> arg3;
            return std::make_unique<JumpCondtitionCommand>(registry, taskManager, arg1, arg2, arg3);
        }
        else
        {
            return std::make_unique<JumpCommand>(registry, taskManager, arg1);
        }
    }
    //2.1
    else if (commandType.compare("/zero") == 0)
    {
        CellAddress addressBegin;
        CellAddress addressEnd;
        inputStream >> addressBegin >> addressEnd;
        return std::make_unique<ZeroRangeCommand>(registry, taskManager, addressBegin, addressEnd);
    }
    //2.2
    else if (commandType.compare("/set") == 0)
    {
        CellAddress address;
        CellValue value;
        inputStream >> address >> value;
        return std::make_unique<SetCommand>(registry, taskManager, address, value);
    }
    //2.3
    else if (commandType.compare("/copy") == 0)
    {
        CellAddress addressFrom;
        CellAddress addressTo;
        longNumber count;
        inputStream >> addressFrom >> addressTo >> count;
        return std::make_unique<CopyCommand>(registry, taskManager, addressFrom, addressTo, count);
    }
    //2.4
    else if (commandType.compare("/mem") == 0)
    {
        CellAddress addressBegin;
        CellAddress addressEnd;
        inputStream >> addressBegin >> addressEnd;
        return std::make_unique<PrintMemoryCommand>(registry, taskManager, addressBegin, addressEnd);
    }
    //2.5
    else if (commandType.compare("/load") == 0)
    {
        String text;
        inputStream >> text;
        return std::make_unique<LoadCommand>(registry, taskManager, text);
    }
    //2.6
    else if (commandType.compare("/run") == 0)
    {
        return std::make_unique<RunCommand>(registry, taskManager);
    }

    //2.8
    else if (commandType.compare("/quote") == 0)
    {
        String command;
        std::getline(inputStream, command);
        return parseCommand(command);
    }
    //2.9
    else if (commandType.compare("/code") == 0)
    {
        return std::make_unique<CodeCommand>(registry, taskManager);
    }
    //2.10
    else if (commandType.compare("/comment") == 0)
    {
        String text;
        std::getline(inputStream,text);
        return std::make_unique<CommentCommand>(registry, taskManager, text);
    }
    else
    {
        return std::make_unique<UnknownCommand>();
    }
}
