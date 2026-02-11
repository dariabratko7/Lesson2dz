#include "MenuFunc.h"




void Menu(char ptr[][30], int row)
{
	for (int i = 0; i < row; i++)
	{
		cout << ptr[i];
		cout << endl;
	}
}

void MenuAddStudents(char**& oldList, int& number)
{
	system("cls");
	int n;
	cout << "Введите количество студентов для добавления в список: ";
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++)
	{

		char* stud_add = new char[20];

		cout << "Введите ім'я студента: ";
		cin.getline(stud_add, 20);

		AddStudents(oldList, number, stud_add);





	}

	system("pause");

}

void MenuPrint(char** list, int number)
{
	system("cls");
	cout << "Список студентов: ";
	cout << endl;
	for (int i = 0; i < number; i++)
		cout << list[i] << endl;
	cout << endl;
	system("pause");
}

void MenuSort(char** list, int number)
{
	system("cls");
	Sort(list, number);
	cout << "Список отсортирован!\n";
	system("pause");
}

void MenuRemoveStudent(char**& oldList, int& number)
{
	system("cls");
	char str[100];
	cout << "Введите фамилию студента для удаления: ";
	cin.getline(str, 100);

	int index = FindStudent(oldList, number, str);

	if (index != -1)
	{
		RemoveStudent(oldList, number, index);
		cout << "Студент удален!\n";
	}
	else
		cout << "Студент не найден!\n";

	system("pause");
}

void MenuEditStudent(char** list, int number)
{
	system("cls");
	char str[100];
	cout << "Введите фамилию студента для модификации: ";
	cin.getline(str, 100);

	int index = FindStudent(list, number, str);

	if (index != -1)
		EditStudent(list, number, index);
	else
		cout << "Студент не найден!\n";

	system("pause");
}

void MenuFindStudent(char** list, int number)
{
	system("cls");
	char str[100];
	cout << "Введите фамилию студента или несколько первых букв: ";
	cin.getline(str, 100);

	int index = FindStudent(list, number, str);

	if (index != -1)
		cout << "Найден студент: " << list[index] << endl;
	else
		cout << "Студент не найден!\n";

	system("pause");
}