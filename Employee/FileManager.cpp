#include "FileManager.h"
#include <fstream>

using namespace std;

void saveToFile(Employee* arr, int size, string filename)
{
    ofstream fout(filename);

    for (int i = 0; i < size; i++)
        fout << arr[i].surname << " "
        << arr[i].name << " "
        << arr[i].age << " "
        << arr[i].position << endl;

    fout.close();
}

void loadFromFile(Employee*& arr, int& size, string filename)
{
    ifstream fin(filename);
    if (!fin) return;

    size = 0;
    string s, n, p;
    int a;

    while (fin >> s >> n >> a >> p) {
        Employee* newArr = new Employee[size + 1];

        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];

        newArr[size] = { s, n, a, p };

        delete[] arr;
        arr = newArr;
        size++;
    }

    fin.close();
}

void saveFiltered(Employee* arr, int size, string filename)
{
    saveToFile(arr, size, filename);
}
