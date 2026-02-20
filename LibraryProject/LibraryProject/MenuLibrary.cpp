#include "MenuLibrary.h"
#include <iostream>
using namespace std;


void showMenu() {
    cout << "\nМеню:\n";
    cout << "1. Друк усіх книг\n";
    cout << "2. Редагувати книгу\n";
    cout << "3. Пошук книги за автором\n";
    cout << "4. Пошук книги за назвою\n";
    cout << "5. Сортування за назвою\n";
    cout << "6. Сортування за автором\n";
    cout << "7. Сортування за видавництвом\n";
    cout << "0. Вихід\n";
    cout << "Виберіть опцію: ";
}

int getChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void handleChoice(int choice, Book books[], int size) {
    switch (choice) {
    case 1:
        printAllBooks(books, size);
        break;

    case 2: {
        int index;
        cout << "Введіть номер книги для редагування (1-" << size << "): ";
        cin >> index;
        cin.ignore();
        if (index >= 1 && index <= size) {
            editBook(books[index - 1]);
        }
        else {
            cout << "Невірний номер книги.\n";
        }
        break;
    }

    case 3: {
        string author;
        cout << "Введіть автора для пошуку: ";
        getline(cin, author);
        searchByAuthor(books, size, author);
        break;
    }

    case 4: {
        string title;
        cout << "Введіть назву для пошуку: ";
        getline(cin, title);
        searchByTitle(books, size, title);
        break;
    }

    case 5:
        sortByTitle(books, size);
        cout << "Книги відсортовані за назвою.\n";
        break;

    case 6:
        sortByAuthor(books, size);
        cout << "Книги відсортовані за автором.\n";
        break;

    case 7:
        sortByPublisher(books, size);
        cout << "Книги відсортовані за видавництвом.\n";
        break;

    case 0:
        cout << "Вихід з програми.\n";
        break;

    default:
        cout << "Невірний вибір. Спробуйте ще.\n";
    }
}