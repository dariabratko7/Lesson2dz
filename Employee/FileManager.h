#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Employee.h"

void saveToFile(Employee* arr, int size, string filename);
void loadFromFile(Employee*& arr, int& size, string filename);
void saveFiltered(Employee* arr, int size, string filename);

#endif
