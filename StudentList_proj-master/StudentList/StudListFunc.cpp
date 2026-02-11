#include "StudListFunc.h"

void AddStudents(char**& list, int& count, char* student)
{

    count++;

    char** temp = new char* [count];
    for (int i = 0; i < count - 1; i++)
        temp[i] = list[i];


    temp[count - 1] = student;
    delete[] list;

    list = temp;
#include "StudListFunc.h"
#include <cstring>

    void AddStudents(char**& list, int& count, char* student)
    {
        count++;

        char** temp = new char* [count];
        for (int i = 0; i < count - 1; i++)
            temp[i] = list[i];

        temp[count - 1] = student;

        delete[] list;
        list = temp;
    }

    void RemoveStudent(char**& list, int& count, int index)
    {
        if (index < 0 || index >= count) return;

        delete[] list[index];

        for (int i = index; i < count - 1; i++)
            list[i] = list[i + 1];

        count--;

        char** temp = new char* [count];
        for (int i = 0; i < count; i++)
            temp[i] = list[i];

        delete[] list;
        list = temp;
    }

    void Sort(char** list, int count)
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (strcmp(list[j], list[j + 1]) > 0)
                {
                    char* temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
    }

    void EditStudent(char** list, int count, int index)
    {
        if (index < 0 || index >= count) return;

        cout << "Введите новое имя: ";
        char buffer[100];
        cin.getline(buffer, 100);

        delete[] list[index];

        list[index] = new char[strlen(buffer) + 1];
        strcpy(list[index], buffer);
    }

    int FindStudent(char** list, int count, char* student)
    {
        for (int i = 0; i < count; i++)
        {
            if (strstr(list[i], student) != nullptr)
                return i;
        }
        return -1;
    }