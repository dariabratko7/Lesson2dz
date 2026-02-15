#include <iostream>
#include "Employee.h"
#include "FileManager.h"
#include "Menu.h"

using namespace std;

int main() {
    Employee* arr = nullptr;
    int size = 0;
    string filename;

    cout << "Введіть ім'я файлу: ";
    cin >> filename;

    loadFromFile(arr, size, filename);

    int choice;

    do {
        showMenu();
        cout << "Ваш вибір: ";
        cin >> choice;

        int index;
        string surname;
        int age;
        char letter;

        switch (choice) {
        case 1:
            addEmployee(arr, size);
            break;
        case 2:
            showAll(arr, size);
            break;
        case 3:
            cout << "Номер: ";
            cin >> index;
            deleteEmployee(arr, size, index - 1);
            break;
        case 4:
            cout << "Номер: ";
            cin >> index;
            editEmployee(arr, size, index - 1);
            break;
        case 5:
            cout << "Прізвище: ";
            cin >> surname;
            searchBySurname(arr, size, surname);
            break;
        case 6:
            cout << "Вік: ";
            cin >> age;
            filterByAge(arr, size, age);
            break;
        case 7:
            cout << "Літера: ";
            cin >> letter;
            filterByLetter(arr, size, letter);
            break;
        case 8:
            saveToFile(arr, size, filename);
            break;
        }

    } while (choice != 0);

    saveToFile(arr, size, filename);
    delete[] arr;

    return 0;
}