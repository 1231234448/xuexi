#include <iostream>
using namespace std;

struct A{
    virtual void fa(){ cout << "A:fa()" << endl; }
    virtual void fb(){ cout << "A:fb()" << endl; }
    void ga(){ cout << "A:ga()" << endl; }
    void gb(int);
    int a;
};
struct B:A{
    virtual void fa(){ cout << "B:fa()" << endl; }
    void ga(){ cout << "A:ga()" << endl; }
    int a;
};
int main()
{
    A* p = new B();
    p->fa();
    p->fb();
    p->ga();
    return 0;
}
