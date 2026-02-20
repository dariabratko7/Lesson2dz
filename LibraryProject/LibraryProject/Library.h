#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void printBook(const Book& b);
void printAllBooks(Book books[], int size);
void editBook(Book& b);
void searchByAuthor(Book books[], int size, const string& author);
void searchByTitle(Book books[], int size, const string& title);
void sortByTitle(Book books[], int size);
void sortByAuthor(Book books[], int size);
void sortByPublisher(Book books[], int size);

#endif#pragma once
