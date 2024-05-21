#include <iostream>
#include "Stroka.h"

using namespace std;

int main() {
    Stroka s1("qwert"), s3, s4(s1), s5;

    s3.vvod();
    Stroka temp("asdfg");
    s3 = temp;
    s3.vyvod();
    cout << endl;

    s5 = s1 + s3 + s4;
    cout << "Длина s5 = " << s5.dlina() << endl;
    s5.vyvod();
    cout << endl;

    if (s1 == s5)
        cout << "строки s1 и s5 равны" << endl;
    else if (s1 == s4)
        cout << "строки s1 и s4 равны" << endl;

    return 0;
}
