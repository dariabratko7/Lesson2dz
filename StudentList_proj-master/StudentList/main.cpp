#include <Windows.h>
#include <conio.h>
#include "MenuFunc.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number = 2;
	char** list = new char* [number] {"FirstStud", "SecondStud"};//



	char menu[][30] = {
		"1. Добавление студентов",
		"2. Удаление студента",
		"3. Модификация студента",
		"4. Вывод на экран списка",
		"5. Сортировка списка",
		"6. Поиск студентов",
		"7. Выход" };
	while (true)
	{
		system("cls");
		Menu(menu, 7);
		int choice = _getch();
		switch (choice)
		{
		case '1':
			MenuAddStudents(list, number);
		
			break;
		case '2':
			MenuRemoveStudent(list, number);
			break;
		case '3':
			MenuEditStudent(list, number);
			break;
		case '4':
			MenuPrint(list, number);
			break;
		case '5':
			MenuSort(list, number);
			break;
		case '6':
			MenuFindStudent(list, number);
			break;
		case '7':
			return;
		}
	}
}