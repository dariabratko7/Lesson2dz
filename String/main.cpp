#include "String.h"

using namespace std;

int main() {
    String s1;
    String s2(50);        
    String s3("Привіт світ");

    s1.input();
    s1.output();

    s2.input();
    s2.output();

    s3.output();

   cout << "Кількість об'єктів: "
        << String::getObjectCount() << endl;

    return 0;
}