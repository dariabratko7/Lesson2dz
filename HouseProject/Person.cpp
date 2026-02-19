#include "Person.h"
#include <cstring>

Person::Person()
{
    fullName = nullptr;
    age = 0;
}

Person::Person(const char* name, int age)
{
    this->age = age;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

Person::Person(const Person& other)
{
    age = other.age;

    if (other.fullName)
    {
        fullName = new char[strlen(other.fullName) + 1];
        strcpy(fullName, other.fullName);
    }
    else
        fullName = nullptr;
}

Person::~Person()
{
    delete[] fullName;
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        delete[] fullName;

        age = other.age;

        if (other.fullName)
        {
            fullName = new char[strlen(other.fullName) + 1];
            strcpy(fullName, other.fullName);
        }
        else
            fullName = nullptr;
    }
    return *this;
}

void Person::setName(const char* name)
{
    delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::print() const
{
    cout << "ПІБ: " << (fullName ? fullName : "Невідомо")
        << ", Вік: " << age << endl;
}