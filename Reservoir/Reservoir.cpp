#include "Reservoir.h"
#include <cstring>
#include <fstream>

Reservoir::Reservoir()
{
    name = nullptr;
    strcpy(type, "Unknown");
    width = length = maxDepth = 0;
}

Reservoir::Reservoir(const char* name, const char* type,
    double width, double length, double depth)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    strcpy(this->type, type);
    this->width = width;
    this->length = length;
    this->maxDepth = depth;
}

Reservoir::Reservoir(const Reservoir& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    strcpy(type, other.type);
    width = other.width;
    length = other.length;
    maxDepth = other.maxDepth;
}

Reservoir::~Reservoir()
{
    delete[] name;
}

Reservoir& Reservoir::operator=(const Reservoir& other)
{
    if (this != &other)
    {
        delete[] name;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        strcpy(type, other.type);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}

double Reservoir::getVolume() const
{
    return width * length * maxDepth;
}

double Reservoir::getSurfaceArea() const
{
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const
{
    return strcmp(type, other.type) == 0;
}

bool Reservoir::compareSurfaceArea(const Reservoir& other) const
{
    if (!isSameType(other))
        return false;

    return getSurfaceArea() > other.getSurfaceArea();
}

void Reservoir::setName(const char* name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

const char* Reservoir::getName() const
{
    return name;
}

void Reservoir::print() const
{
    cout << "Назва: " << name
        << "\nТип: " << type
        << "\nШирина: " << width
        << "\nДовжина: " << length
        << "\nМакс. глибина: " << maxDepth
        << "\nПлоща: " << getSurfaceArea()
        << "\nОбʼєм: " << getVolume()
        << "\n------------------------\n";
}

void Reservoir::saveToText(ofstream& out) const
{
    out << name << " "
        << type << " "
        << width << " "
        << length << " "
        << maxDepth << endl;
}

void Reservoir::saveToBinary(ofstream& out) const
{
    int nameLen = strlen(name);
    out.write((char*)&nameLen, sizeof(nameLen));
    out.write(name, nameLen);

    out.write(type, sizeof(type));
    out.write((char*)&width, sizeof(width));
    out.write((char*)&length, sizeof(length));
    out.write((char*)&maxDepth, sizeof(maxDepth));
}
