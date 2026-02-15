#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

struct Employee {
	string surname;
	string name;
	int age;
	string position;
};

void addEmployee(Employee*& arr, int& size);
void ShowAll(Employee* arr, int size);
void deleteEmployee(Employee*& arr, int& size, int index);
void editEmployee(Employee* arr, int size, int index);
void searchBySurname(Employee* arr, int size, string surname);
void filterByAge(Employee* arr, int size, int age);
void filterByLetter(Employee* arr, int size, char letter);

#endif