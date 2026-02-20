#include "ReservoirArray.h"
#include <fstream>

ReservoirArray::ReservoirArray()
{
    data = nullptr;
    size = 0;
}

ReservoirArray::~ReservoirArray()
{
    delete[] data;
}

void ReservoirArray::add(const Reservoir& r)
{
    Reservoir* temp = new Reservoir[size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = data[i];

    temp[size] = r;

    delete[] data;
    data = temp;
    size++;
}

void ReservoirArray::remove(int index)
{
    if (index < 0 || index >= size) return;

    Reservoir* temp = new Reservoir[size - 1];

    for (int i = 0, j = 0; i < size; i++)
    {
        if (i != index)
            temp[j++] = data[i];
    }

    delete[] data;
    data = temp;
    size--;
}

void ReservoirArray::print() const
{
    for (int i = 0; i < size; i++)
        data[i].print();
}

void ReservoirArray::saveText(const char* filename) const
{
    ofstream out(filename);
    for (int i = 0; i < size; i++)
        data[i].saveToText(out);
}

void ReservoirArray::saveBinary(const char* filename) const
{
    ofstream out(filename, ios::binary);
    for (int i = 0; i < size; i++)
        data[i].saveToBinary(out);
}