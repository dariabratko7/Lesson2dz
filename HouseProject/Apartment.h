#pragma once
#include "Person.h"

class Apartment
{
private:
    Person* residents;
    int residentCount;

public:
    Apartment();
    Apartment(int count);
    Apartment(const Apartment& other);
    ~Apartment();

    Apartment& operator=(const Apartment& other);

    void setResident(int index, const Person& person);
    void print() const;
};
