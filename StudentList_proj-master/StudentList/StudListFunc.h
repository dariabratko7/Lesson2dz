#pragma once


#include <windows.h>
#include <iostream>

using namespace std;


/// чисті функції для роботи зі списком студентів//



void AddStudents(char**& list, int& count, char* student);
void RemoveStudent(char**& list, int& count, int index);

void Print(char** list, int count);
void Sort(char** list, int count);

void EditStudent(char** list, int count, int index);
int FindStudent(char** list, int count, char* student);