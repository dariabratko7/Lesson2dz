#include "Apartment.h"

Apartment::Apartment()
{
    residents = nullptr;
    residentCount = 0;
}

Apartment::Apartment(int count)
{
    residentCount = count;
    residents = new Person[count];
}

Apartment::Apartment(const Apartment& other)
{
    residentCount = other.residentCount;
    residents = new Person[residentCount];

    for (int i = 0; i < residentCount; i++)
        residents[i] = other.residents[i];
}

Apartment::~Apartment()
{
    delete[] residents;
}

Apartment& Apartment::operator=(const Apartment& other)
{
    if (this != &other)
    {
        delete[] residents;

        residentCount = other.residentCount;
        residents = new Person[residentCount];

        for (int i = 0; i < residentCount; i++)
            residents[i] = other.residents[i];
    }
    return *this;
}

void Apartment::setResident(int index, const Person& person)
{
    if (index >= 0 && index < residentCount)
        residents[index] = person;
}

void Apartment::print() const
{
    cout << "Мешканці квартири:\n";
    for (int i = 0; i < residentCount; i++)
        residents[i].print();
}