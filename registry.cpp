#include "registry.hpp"
using iterator = std::map<CellAddress, CellValue>::iterator;

// Set value of cell to 0
void Registry::resetCell(CellAddress address)
{
    if (cellIsZero(address))
        return;
    registry.erase(address);
}

// Increment value of cell
void Registry::incrementCellValue(CellAddress address)
{
    if (cellIsZero(address))
    {
        registry[address] = 0;
    }
    registry.at(address)++;
}
void Registry::copyCellValue(CellAddress source, CellAddress target)
{
    if (cellIsZero(source))
    {
        resetCell(target);
    }
    else
    {
        registry[target] = registry.at(source);
    }
}
void Registry::resetRange(CellAddress begin, CellAddress end)
{
    iterator beginRange = registry.lower_bound(begin);
    iterator endRange = registry.upper_bound(end);
    iterator it;

    for (it = beginRange; it != endRange;)
    {
        //std::cout<<it->first<<std::endl;
        registry.erase(it++);
    }
}
//set x y
void Registry::setCellValue(CellAddress address, CellValue value)
{
    if (value == 0)
    {
        resetCell(address);
    }
    else
    {
        registry[address] = value;
    }
}
//copy x y z
void Registry::copyRange(CellAddress sourceBegin, CellAddress targetBegin, longNumber cellCount)
{

    //Iterate non-ZERO elements of sourceRange and copy them in targetRange
    for (CellAddress i = sourceBegin; i < sourceBegin + cellCount; i++)
    {
        if (registry.count(i))
        {
            registry[i + targetBegin - sourceBegin] = registry[i];
        }
        else
        {
            registry.erase(i + targetBegin - sourceBegin);
        }
    }
}
//mem x y
void Registry::printRange(CellAddress start, CellAddress end, std::ostream &out)
{
    iterator beginRange = registry.lower_bound(start);
    iterator endRange = registry.upper_bound(end);

    out << "{ ";
    for (iterator it = beginRange; it != endRange; it++)
    {
        out << "[ " << it->first << " : " << it->second << " ] ";
    }
    out << "}" << std::endl;
}

CellValue Registry::valueAt(CellAddress cellAddress)
{
    if (registry.count(cellAddress))
    {
        return registry[cellAddress];
    }
    return 0;
}

bool Registry::cellIsZero(CellAddress address)
{
    if (registry.count(address))
    {
        return registry.at(address) == 0;
    }
    return true;
}