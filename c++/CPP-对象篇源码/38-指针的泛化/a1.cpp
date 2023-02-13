#include <iostream>
using namespace std;

class A{
public:
    void f() { cout << "A::f()" << endl; }
private:
    int a;
};
class B: public A{
public:
    void f() { cout << "B::f()" << endl; }
private:
    int b;
};
int main()
{
    B x;
    x.f();
    A* p = &x;
    p->f();
    return 0;
}
