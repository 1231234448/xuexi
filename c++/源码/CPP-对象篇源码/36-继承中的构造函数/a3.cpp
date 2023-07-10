#include <iostream>

using namespace std;

struct A{
    A(){ cout << "A::A()" << endl; }
    A(int){ cout << "A::A(int)" << endl; }
};
struct B1: virtual public A{
    B1(){ cout << "B1::B1()" << endl; }
};
struct B2: virtual public A{
    B2(){ cout << "B2::B2()" << endl; }
};
struct C: public B1, public B2{
    C():A(33){ cout << "C::C()" << endl; }
};
int main()
{
    C x;
    return 0;
}

