#include <iostream>

using namespace std;

struct A{
    A(){ cout << "A::A()" << endl; }
    A(int a, char* b){ cout << "A::A(int, char*)" << endl; }
};
struct B: public A{
    B():A(10,"abc"){ cout << "B::B()" << endl; }
    B(int x){ cout << "B::B(int)" << endl; }
};

int main()
{
    B x(100);
    B y;
    return 0;
}
