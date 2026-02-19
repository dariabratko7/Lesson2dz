#include "Building.h"

Building::Building()
{
    apartments = nullptr;
    apartmentCount = 0;
}

Building::Building(int count)
{
    apartmentCount = count;
    apartments = new Apartment[count];
}

Building::Building(const Building& other)
{
    apartmentCount = other.apartmentCount;
    apartments = new Apartment[apartmentCount];

    for (int i = 0; i < apartmentCount; i++)
        apartments[i] = other.apartments[i];
}

Building::~Building()
{
    delete[] apartments;
}

Building& Building::operator=(const Building& other)
{
    if (this != &other)
    {
        delete[] apartments;

        apartmentCount = other.apartmentCount;
        apartments = new Apartment[apartmentCount];

        for (int i = 0; i < apartmentCount; i++)
            apartments[i] = other.apartments[i];
    }
    return *this;
}

void Building::setApartment(int index, const Apartment& apartment)
{
    if (index >= 0 && index < apartmentCount)
        apartments[index] = apartment;
}

void Building::print() const
{
    cout << "Будинок містить " << apartmentCount << " квартир\n\n";

    for (int i = 0; i < apartmentCount; i++)
    {
        cout << "Квартира №" << i + 1 << endl;
        apartments[i].print();
        cout << endl;
    }
}