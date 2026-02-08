#include <iostream>
#include "MenuFraction.h"
using namespace std;

void showMenu() {
    cout << "\n--- Меню ---\n";
    cout << "1. Додавання дробів\n";
    cout << "2. Віднімання дробів\n";
    cout << "3. Множення дробів\n";
    cout << "4. Ділення дробів\n";
    cout << "0. Вихід\n";
    cout << "Ваш вибір: ";
}

void processMenu() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            Fraction a, b, result;
            cout << "\nПерший дріб:\n";
            a.input();
            cout << "Другий дріб:\n";
            b.input();

            switch (choice) {
            case 1:
                result = a.add(b);
                cout << "Сума: ";
                break;
            case 2:
                result = a.subtract(b);
                cout << "Різниця: ";
                break;
            case 3:
                result = a.multiply(b);
                cout << "Добуток: ";
                break;
            case 4:
                result = a.divide(b);
                cout << "Частка: ";
                break;
            }

            result.print();
        }

    } while (choice != 0);
}
