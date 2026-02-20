#pragma once
#include <iostream>
using namespace std;

class Reservoir
{
private:
    char* name;
    char type[20];
    double width;
    double length;
    double maxDepth;

public:
    Reservoir();
    explicit Reservoir(const char* name, const char* type,
        double width, double length, double depth);

    Reservoir(const Reservoir& other);
    ~Reservoir();

    Reservoir& operator=(const Reservoir& other);

    double getVolume() const;
    double getSurfaceArea() const;

    bool isSameType(const Reservoir& other) const;
    bool compareSurfaceArea(const Reservoir& other) const;

    void setName(const char* name);
    const char* getName() const;

    void print() const;

    void saveToText(ofstream& out) const;
    void saveToBinary(ofstream& out) const;
};
