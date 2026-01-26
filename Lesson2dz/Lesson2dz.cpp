// Lesson2dz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*Створити застосунок, який виводить інформацію про книгу в такому форматі :
Name: "Тигролови"
Author : Іван Багряний
Publisher : Київ
Pages : 320*/

    cout << "Name: \"Тигролови\"" << endl;
    cout << "Author: Іван Багряний" << endl;
    cout << "Publisher: Київ" << endl;
    cout << "Pages: 320" << endl;

    return 0;

//Завдання 2
//Створити застосунок, який виводить на консоль фразу :
//
//"Щедрик, щедрик, щедрівочка,
//Прилетіла ластівочка,
//Стала собі щебетати,
//Господаря викликати"
//
//Виконати в двох варіантах : R строки і з використанням Escape
    /*варіант1*/
    cout << R"(
"Щедрик, щедрик, щедрівочка,
Прилетіла ластівочка,
Стала собі щебетати,
Господаря викликати"
)" << endl;

    return 0;

    ///*варіант2*/

    cout << "\"Щедрик, щедрик, щедрівочка,\n"
        "Прилетіла ластівочка,\n"
        "Стала собі щебетати,\n"
        "Господаря викликати\""
        << endl;

    return 0;

//Завдання 3
//Створити застосунок, який виводить на екран наступну таблицю :
//╔══════════════════════════════════════════════════════════════════════════════╗
//║                                  Vremena goda                                      ║
//╠═════════════════════╦═════════════════════╦═════════════════════╦════════════╣
//║       Zima          ║        Vesna        ║         Leto        ║       Osen       ║
//╚═════════════════════╩═════════════════════╩═════════════════════╩════════════╝
//Підказка :
//Рекомендуємо виконати такий приклад :
//cout << "\n" << (char)201 << (char)205 << (char)205 << (char)187;
//Необхідні символи знаходяться в діапазоні 179–218.

    int main()
    {
        char HL = (char)196;
        char VL = (char)179;
        char TL = (char)218;
        char TR = (char)191;
        char BL = (char)192;
        char BR = (char)217;
        char TJ = (char)194;
        char BJ = (char)193;
        char LJ = (char)195;
        char RJ = (char)180;
        char CJ = (char)197;

        cout << TL;
        for (int i = 0; i < 65; i++) cout << HL;
        cout << TR << endl;

        cout << VL << "                             Vremena goda                               " << VL << endl;

        cout << LJ;
        for (int i = 0; i < 65; i++) cout << HL;
        cout << RJ << endl;

        cout << VL << "   Zima      " << VL << "   Vesna      " << VL << "   Leto      " << VL << "   Osen      " << VL << endl;

        cout << BL;
        for (int i = 0; i < 65; i++) cout << HL;
        cout << BR << endl;

        return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
