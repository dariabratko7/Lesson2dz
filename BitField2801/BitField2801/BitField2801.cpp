#include <stdio.h>
#include<iostream>
using namespase std

//1.Написать структуру битовых полей для хранения :
//
//hours – количество часов в одних сутках 0..23;  2 ^ 5 = 32  :5
//minutes – количество минут в часе 0..59; ? ? ? ? ? ? сколько бит 2 ^ ? ? ?
//seconds – количество секунд в минуте 0..59;
//milliseconds – количество миллисекунд 0..999.
struct Time {
	unsigned int hours : 5;
	unsigned int minutes : 6;
	unsigned int seconds : 6;
	unsigned int miliseconds : 10;
};

int main() {
	struct Time t = { 12, 34, 56, 789 };

	printf("Time: %02u:%02u:%02u.%03u\n",
		t.hours, t.minutes, t.seconds, t.miliseconds);

	return 0;
}



//1.1 Создать обьект в main, протестировать.
//Работаете со структурой как обычно
//- Написать функцию ввода с клавиатуры часов, минут, секунд, миллисекунд и сохранение введенных
//данных в структуру битовых полей
//- Написать функцию вывода данных  структуры битовых полей на экран
//- Определите размер структуры битовых полей
//- Какой размер имела бы такая структура без использования битовых полей

stuct Time{
	unsigned int hours : 5;
	unsigned int minutes : 6;
	unsigned int seconds : 6;
	unsigned int milliseconds : 10;

};

void inputTime(Time& t) {
	cout << "Enter hours(0-23):";
	cin >> t.hours;

	cout << "Enter minutes(0-59):";
	cin >> t.minutes;

	cout << "Enter seconds(0-59):";
	cin >> t.seconds;

	cout << "Enter milliseconds(0-990):";
	cin >> t.milliseconds;

}

void printTime(const Time& t) {
	cout << "Time:"
		<< t.hours << ":"
		<< t.minutes << ":"
		<< t.seconds << ":"
		<< t.milliseconds << endl;
}

int main() {
	Time t;

	inputTime(t);
	printTime(t);

	cout << "Stuct size with bite field:"
		<< sizeof(Time) << "bite" << endl;
	return 0;
}