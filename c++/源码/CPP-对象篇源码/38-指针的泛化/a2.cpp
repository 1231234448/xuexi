#include <iostream>
using namespace std;

struct A{
    void f() { cout << "A::f()" << endl; }
    int a;
};
struct A2{
    int a2;
};
struct B: A, A2{
    void f() { cout << "B::f()" << endl; }
    int b;
};
int main()
{
    B x;
    cout << &x << endl;
    A2* p = &x;
    cout << p << endl;
    return 0;
}
