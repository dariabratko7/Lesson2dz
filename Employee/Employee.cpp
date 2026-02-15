#include "Employee.h"
#include <iostream>

using namespace std;

void addEmployee(Employee*& arr, int& size)
{
	Employee* newArr = new Employee[size + 1];

	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];

	cout << "Прізвище:";
	cin >> newArr[size].surname;

	cout << "Ім'я:";
	cin >> newArr[size].name;

	cout << "Вік:";
	cin >> newArr[size].age;

	cout << "Посада:";
	cin >> newArr[size].position;

	delete[] arr;
	arr = newArr;
	size++;
}

void ShowAll(Employee* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "."
			<< arr[i].surname << " "
			<< arr[i].name << ", "
			<< arr[i].age << " років, "
			<< arr[i].position << endl;
	}
}

void deleteEmployee(Employee*& arr, int& size, int index)
{
	if (index < 0 || index >= size) return;

	Employee* newArr = new Employee[size - 1];

	for (int i = 0, j = 0; i < size; i++)
		if (i != index)
			newArr[j++] = arr[i];

	delete[] arr;
	arr = newArr;
	size--;
}

void editEmployee(Employee* arr, int size, int index)
{
	if (index < 0 || index >= size) return;

	cout << "Нове прізвище: ";
	cin >> arr[index].surname;

	cout << "Нове ім'я: ";
	cin >> arr[index].name;

	cout << "Новий вік: ";
	cin >> arr[index].age;

	cout << "Нова посада: ";
	cin >> arr[index].position;
}

void searchBySurname(Employee* arr, int size, string surname)
{
	for (int i = 0; i < size; i++)
		if (arr[i].surname == surname)
			cout << arr[i].surname << " "
			<< arr[i].name << " "
			<< arr[i].age << " "
			<< arr[i].position << endl;
}

void filterByAge(Employee* arr, int size, int age)
{
	for (int i = 0; i < size; i++)
		if (arr[i].age == age)
			cout << arr[i].surname << " "
			<< arr[i].name << endl;
}

void filterByLetter(Employee* arr, int size, char letter)
{
	for (int i = 0; i < size; i++)
		if (arr[i].surname[0] == letter)
			cout << arr[i].surname << " "
			<< arr[i].name << endl;
}





