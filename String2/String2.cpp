﻿#include "String2.h"
#include <cstring>

using namespace std;

int String::objectCount = 0;


String::String(size_t size) :capacity(size), length(0)
{
	str = new char[capacity + 1];
	str[0] = '\0';
	objectCount++;
}

String::String() : String(80) {}

String::String(const char* input) :String(strlen(input))
{
	length = strlen(input);
	strcpy(str, input);
}
String::~String() {
	delete[] str;
	objectCount--;
}

void String::input()
{
	cout << "Введіть рядок: ";
	cin.getline(str, capacity + 1);
	length = strlen(str);
}

void String::output() const
{
	cout << "Рядок: " << str << endl;
}

int String::getObjectCount()
{
	return objectCount;
}

///ДОБАВЛЯЮ НОВЕ 
// Конструктор перенесення
String::String(String&& other) noexcept
    : str(other.str), length(other.length), capacity(other.capacity)
{
    other.str = nullptr;
    other.length = 0;
    other.capacity = 0;
    objectCount++;
}

// Оператор присвоєння перенесення
String& String::operator=(String&& other) noexcept
{
    if (this != &other) {
        delete[] str; // звільняємо свою пам'ять

        str = other.str;
        length = other.length;
        capacity = other.capacity;

        other.str = nullptr;
        other.length = 0;
        other.capacity = 0;
    }
    return *this;
}
