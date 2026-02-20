#include <iostream>
#include "Point.h"

using namespace std;


int main()
{
	/////1.  Operator +


	//int a = 5.2;
	//int b = 6;
	//cout << a + b << endl;

	//int c = a + b;/////     int operator + (int b) const   це оператор визивається на об'єкті а


	////  Пример перегрузки методами класса

	///левый операнд передается в указатель this   , а правый заходит параметром

	Point p1(1, 2);
	Point p2(3, 4);

	///if (p2>p1)

	//Point p3 = p1 + p2;///  operator + визивається для лівого операнда p1(this), праввий операнд p2 заходить параметром 

	//p3.Show();


	//Point res = p1 + p2 + p3;//

	//res.Show();

	//p1 += 5 ;


	//                    ////Point operator +(const Point& р2) const;  --  екземплярний варіант
	///*p1.Show();
	//p2.Show();
	//rez.Show();*/


	Point rez2 = p1 + 2;//// operator + визивається для лівого операнда p1(this),праввий операнд число 2 заходить параметром 
	//                    //// Point operator+ (int numb)const;

	rez2.Show();


    Point rez3 = 2 + p1;/////////Глобальними функціями
	//                    ///////  Point operator+(int number, const Point & obj)///// перегрузка глобальною функцією  int+Point
	//                    //////    Point operator+( const Point & obj, int number,)////перегрузка глобальною функцією  Poin+int



	////////2.Point operator +=(int rs)   

	//Point a(2, 3);

	//a += 2;
	//a.Show();


	/////3.  Оператор перетворення типів operator int() ,   explicit  Pont---->int  
	
	/*Point a(2, 3);

	cout << int(a) << endl;*/


	//////4.  Increment ++

	//int a = 5;

	//cout << (a++) << endl;  ///5
	//cout << a << endl;    //6

	//cout << (++a)++ << endl;////   префіксна форма одразу змінює об'єкт int& operator++ ()  this


	//a = 5;
	//cout << (a++)++ << endl;////   постфіксна форма  змінює об'єкт  після  int operator++ (int i)



	// Point obj(2,3);
	 //(obj++)++;///Point operator ++(int i);
	 //obj.Show();



	// (++obj)++;//////	 Point& operator ++();
	 //obj.Show();


	


	 
}