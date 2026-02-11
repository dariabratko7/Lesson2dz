#include <iostream>
#include "PhoneBook.h"

using namespace std;

int main()
{
    PhoneBook book;
    int choice;
    string name, home, work, mobile, info, filename;

    do
    {
        cout << "\n===== Телефонна книга =====\n";
        cout << "1. Додати абонента\n";
        cout << "2. Видалити абонента\n";
        cout << "3. Знайти абонента\n";
        cout << "4. Показати всіх\n";
        cout << "5. Зберегти у файл\n";
        cout << "6. Завантажити з файлу\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "ФІО: ";
            getline(cin, name);

            cout << "Домашній телефон: ";
            getline(cin, home);

            cout << "Робочий телефон: ";
            getline(cin, work);

            cout << "Мобільний телефон: ";
            getline(cin, mobile);

            cout << "Додаткова інформація: ";
            getline(cin, info);

            book.AddContact(Contact(name.c_str(), home, work, mobile, info));
            cout << "Абонента додано!\n";
            break;

        case 2:
            cout << "Введіть ФІО для видалення: ";
            getline(cin, name);
            book.DeleteContact(name);
            break;

        case 3:
            cout << "Введіть ФІО для пошуку: ";
            getline(cin, name);
            book.FindContact(name);
            break;

        case 4:
            book.ShowAll();
            break;

        case 5:
            cout << "Введіть ім'я файлу: ";
            getline(cin, filename);
            book.Save(filename);
            cout << "Збережено!\n";
            break;

        case 6:
            cout << "Введіть ім'я файлу: ";
            getline(cin, filename);
            book.Load(filename);
            cout << "Завантажено!\n";
            break;

        case 0:
            cout << "Вихід з програми.\n";
            break;

        default:
            cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}