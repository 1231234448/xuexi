#include <iostream>
using namespace std;

struct A{
    int a;
};
struct B1: A{
    int b1;
};
struct B2: A{
    int b2;
};
struct C:B1,B2{
    int c;
};

int main()
{
    C x;
    cout << sizeof(x) << endl;
    cout << &(x.B1::a) << endl;
    cout << &(x.b1) << endl;
    cout << &(x.B2::a) << endl;
    cout << &(x.b2) << endl;
    cout << &(x.c) << endl;

    return 0;
}
