
#pragma once
#include <windows.h>
#include <iostream>
#include "StudListFunc.h"
using namespace std;

void MenuAddStudents(char **&, int &);
void MenuRemoveStudent(char**&, int&);

void MenuPrint(char **, int);
void MenuSort(char **, int);

void MenuEditStudent(char **, int);
void MenuFindStudent(char **, int);
void Menu(char ptr[][30], int row);