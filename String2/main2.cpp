#include "String2.h"

using namespace std;

int main() {
    String s1;
    String s2(50);
    String s3("Ïðèâ³ò ñâ³ò");

    s1.input();
    s1.output();

    s2.input();
    s2.output();

    s3.output();

    cout << "Ê³ëüê³ñòü îá'ºêò³â: "
        << String::getObjectCount() << endl;

    return 0;
}