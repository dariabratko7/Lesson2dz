
#pragma once
#include <iostream>

using namespace std;

class Person
{
private:
	char* fullName;
	int age;


public:
	Person();
	Person(const char* name, int age);
	Person(const Person& other);
	~Person();

	Person& operator=(const Person& other);

	void setName(const char* name);
	void setAge(int age);
	void print() const;

};