#include <iostream>
#include <typeinfo>
using namespace std;

struct A{virtual void f(){}};
struct B:A{int x;};
int main()
{
    A* p = new B();
    cout << typeid("abc").name() << endl;
    cout << typeid(123.5).name() << endl;
    cout << typeid(p).name() << endl;
    cout << typeid(*p).name() << endl;
    cout << typeid(B).name() << endl;
    return 0;
}
