#pragma once
#include "Reservoir.h"

class ReservoirArray
{
private:
    Reservoir* data;
    int size;

public:
    ReservoirArray();
    ~ReservoirArray();

    void add(const Reservoir& r);
    void remove(int index);
    void print() const;

    void saveText(const char* filename) const;
    void saveBinary(const char* filename) const;
};
