#pragma once
#include "Apartment.h"

class Building
{
private:
    Apartment* apartments;
    int apartmentCount;

public:
    Building();
    Building(int count);
    Building(const Building& other);
    ~Building();

    Building& operator=(const Building& other);

    void setApartment(int index, const Apartment& apartment);
    void print() const;
};
