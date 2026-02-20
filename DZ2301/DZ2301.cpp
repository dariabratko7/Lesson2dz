#include "DZ2301.h"
#include <iomanip>

void InitDate(tm& date, int y, int m, int d)
{
	date = {};
	date.tm_year = y - 1900;
	date.tm_mon = m - 1;
	date.tm_mday = d;
}

void PrintDate(const tm& date)
{
	cout << setw(4) << date.tm_year + 1900 << "/ " << setw(2) << date.tm_mon + 1 << "/ " << date.tm_mday << endl;
}

void PrintDate(const DateArr& arrDate)////  int** arr, int size
{
	int size = arrDate.size;
	for (int i = 0; i < size; i++)
	{
		PrintDate(*(arrDate.arr[i]));
	}
}

void InsertByIndex(DateArr& arrDate, tm* newDate, int index)
{
	int size = arrDate.size;
	if (index < 0 || index > size)
	{
		return;
	}

	tm** temp = new tm * [size + 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = arrDate.arr[i];
	}

	temp[index] = newDate;

	for (int i = index; i < size; i++)
	{
		temp[i + 1] = arrDate.arr[i];
	}
	delete[] arrDate.arr;

	arrDate.arr = temp;
	arrDate.size++;


}

void AddLast(DateArr& arrDate, tm* newDate)
{
	InsertByIndex(arrDate, newDate, arrDate.size);
}

void DellByIndex(DateArr& arrDate, tm* newDate, int index)
{
	if (!newDate)
		return;

	if (index < 0 || index >= arrDate.size)
		return;

	if (arrDate.arr[index]->tm_year != newDate->tm_year ||
		arrDate.arr[index]->tm_mon != newDate->tm_mon ||
		arrDate.arr[index]->tm_mday != newDate->tm_mday)
		return;

	delete arrDate.arr[index];

	tm** temp = new tm * [arrDate.size - 1];

	for (int i = 0; i < index; i++)
	{
		temp[i] = arrDate.arr[i];
	}

	for (int i = index + 1; i < arrDate.size; i++) {
		temp[i - 1] = arrDate.arr[i];
	}

	delete[] arrDate.arr;

	arrDate.arr = temp;
	arrDate.size--;

}

int FindFirst(DateArr& arrDate, tm* date)
{
	if (!date)
		return -1;

	for (int i = 0; i < arrDate.size; i++)
	{
		if (arrDate.arr[i]->tm_year == date->tm_year &&
			arrDate.arr[i]->tm_mon == date->tm_mon &&
			arrDate.arr[i]->tm_mday == date->tm_mday)
		{
			return i;
		}
	}

	return -1;
}

bool CompareDate(tm* date1, tm* date2)
{

	time_t t1 = mktime(date1);/// sec since 1900   35400s
	time_t t2 = mktime(date2);////  sec since 1900   39400s

	return t1 > t2;
}


void Sort(DateArr& arrDate)
{
	int size = arrDate.size;

	for (int n = 1; n < size; n++)
	{
		for (int i = 0; i < size - n; i++)
		{
			if (CompareDate(arrDate.arr[i], arrDate.arr[i + 1]))
			{
				swap(arrDate.arr[i], arrDate.arr[i + 1]);
			}
		}
	}
}

void InsertSort(DateArr& arrDate)
{
	int size = arrDate.size;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0; j--)
			if (arrDate.arr[j] < arrDate.arr[j - 1])
				swap(arrDate.arr[j], arrDate.arr[j - 1]);
			else break;
	}
}



void SaveToFile(const char* filePath, const DateArr& arrDate)
{
	FILE* f = nullptr;
	fopen_s(&f, filePath, "wb");
	if (!f) return;

	// 1. сохраняем количество элементов
	fwrite(&arrDate.size, sizeof(int), 1, f);

	// 2. сохраняем сами даты
	for (int i = 0; i < arrDate.size; i++)
	{
		fwrite(arrDate.arr[i], sizeof(tm), 1, f);
	}

	fclose(f);
}

void ReadFromFile(const char* filePath, DateArr& arrDate)
{
	FILE* f = nullptr;
	fopen_s(&f, filePath, "rb");
	if (!f) return;

	// 1. освобождаем старые данные
	for (int i = 0; i < arrDate.size; i++)
	{
		delete arrDate.arr[i];
	}
	delete[] arrDate.arr;

	// 2. читаем размер
	fread(&arrDate.size, sizeof(int), 1, f);

	// 3. выделяем память
	arrDate.arr = new tm * [arrDate.size];

	// 4. читаем даты
	for (int i = 0; i < arrDate.size; i++)
	{
		arrDate.arr[i] = new tm;
		fread(arrDate.arr[i], sizeof(tm), 1, f);
	}

	fclose(f);
}
