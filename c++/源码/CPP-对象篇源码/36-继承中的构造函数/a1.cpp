#include <iostream>

using namespace std;

struct A{
    A(){ cout << "A::A()" << endl; }
};
struct B:A{
    B(int x){ cout << "B::B(int)" << endl; }
};

int main()
{
    B x(100);
    return 0;
}
