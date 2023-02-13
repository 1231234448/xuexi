#include <iostream>
using namespace std;

struct A{
    virtual void f(){ cout << "A::f" << endl; }
};
struct B1:A{
    virtual void f(){ cout << "B1::f" << endl; }
};
struct B2:A{
    virtual void f(){ cout << "B2::f" << endl; }
};
int main()
{
    A* p;
    int x;
    cin >> x;
    if(x<5)
        p = new B1();
    else
        p = new B2();
    p->f();  // 如何编译这个 f()?
    return 0;
}
