#include <iostream>

using namespace std;

class A{
public:
    int a;
};
class B1: public A{};
class B2: public A{};
class C:public B1, public B2{};

int main()
{
    C x;
    x.B1::a = 10;
    x.B2::a = 20;
    cout << x.B1::a << "," << x.B2::a << endl;
    return 0;
}
