#include <iostream>
using namespace std;

typedef int (*MYF)(int);
int f1(int a) { return a*2; }
int f2(int a) { return a/2; }

void f(int x, MYF fp)
{
    cout << "I will call fp: ";
    cout << (*fp)(x) << endl;
}

int main()
{
    f(100, f1);
    return 0;
}
