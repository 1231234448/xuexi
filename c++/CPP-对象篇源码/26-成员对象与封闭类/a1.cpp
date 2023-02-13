#include <iostream>

using namespace std;

class A{
public:
    A(){ cout << "A()" << endl; }
    A(int a) { cout << "A(a)" << endl; this->a = a; }
private:
    int a;
};

class B{
public:
    B(int a, int b):x(a){ y = b; }
private:
    A x;
    int y;
};

int main()
{
    B t(1,2);
    return 0;
}
