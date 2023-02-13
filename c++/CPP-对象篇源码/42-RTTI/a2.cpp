#include <iostream>
#include <typeinfo>
using namespace std;

struct A{
    virtual void f(){ cout << "A::f()" << endl; }
};
struct B{
    virtual void g(){ cout << "B::g()" << endl; }
};
struct C:A,B{
    void h() { cout << "C::h()" << endl; }
};
int main()
{
    B* p = new C();
    if(typeid(*p)==typeid(C)){
        C* q = dynamic_cast<C*>(p);
        q->h();
    }
    return 0;
}
