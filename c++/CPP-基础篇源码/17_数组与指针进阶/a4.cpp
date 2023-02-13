#include <iostream>
using namespace std;


void f(int (&p)[3])
{
    cout << sizeof(p) << endl;
}

void g(int p[3])  // 3 is ignored
{
    cout << sizeof(p) << endl;
}

int main()
{
    int a[3];
    f(a);
    g(a);
    return 0;
}
