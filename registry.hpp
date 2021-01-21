#ifndef REGISTRY
#define REGISTRY
#include <iostream>
#include <map>
using longNumber = unsigned long long;
using CellAddress = unsigned long long;
using CellValue = unsigned long long;
class Registry
{
private:
    std::map<CellAddress, CellValue> registry;

    bool cellIsZero(CellAddress cellAddress);

public:
    //ZERO x
    void resetCell(CellAddress address);
    //INC n
    void incrementCellValue(CellAddress address);
    //MOVE x y
    void copyCellValue(CellAddress from, CellAddress to);
    //zero x y
    void resetRange(CellAddress begin, CellAddress end);
    //set x y
    void setCellValue(CellAddress address, CellValue value);
    //copy x y z
    void copyRange(CellAddress from, CellAddress to, longNumber cellCount);
    //mem x y
    void printRange(CellAddress from, CellAddress to, std::ostream &out = std::cout);

    CellValue valueAt(CellAddress cellAddress1);
};
#endif