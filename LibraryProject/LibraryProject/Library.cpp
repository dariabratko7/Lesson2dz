#include "Library.h"
#include <iostream>
#include <algorithm>
using namespace std;

void printBook(const Book& b) {
    cout << "Назва: " << b.title
        << ", Автор: " << b.author
        << ", Видавництво: " << b.publisher
        << ", Жанр: " << b.genre << endl;
}

void printAllBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". ";
        printBook(books[i]);
    }
}

void editBook(Book& b) {
    cout << "Редагування книги:\n";
    cout << "Нова назва:"; getline(cin, b.title);
    cout << "Новий автор:"; getline(cin, b.author);
    cout << "Нове видавництво:"; getline(cin, b.publisher);
    cout << "Новий жанр:"; getlent(cin, b.genre);
}

void searchByAuthor(Book books[], int size const string& author) {
    bool found = false;
    for (int i = 0, i < size; i++) {
        if (books[i].author == author) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) cout << "Книга автора" << author << "не знайдено.\n";
}

void searchByTitle(Book books[], int size, const string& title) {
    bool found = false;
    for (int i = 0, i < size; i++) {
        if (books[i].title == title) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) cout << "Книги з назвою\"" << title << "\"не знайдено.\n";
}

void sortByTitle(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
}

void sortByAuthor(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
}

void sortByPublisher(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        retutn a.publisher < b.publisher;
        });
}