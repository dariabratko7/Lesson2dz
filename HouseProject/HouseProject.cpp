#include "Building.h"

int main()
{
    Person p1("Іван Петренко", 30);
    Person p2("Марія Коваль", 25);
    Person p3("Олег Бондар", 40);

    Apartment a1(2);
    a1.setResident(0, p1);
    a1.setResident(1, p2);

    Apartment a2(1);
    a2.setResident(0, p3);

    Building house(2);
    house.setApartment(0, a1);
    house.setApartment(1, a2);

    house.print();

    return 0;
}