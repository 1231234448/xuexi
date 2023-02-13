#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

template <int N>
void f(int (&x)[N])
{
    cout << typeid(x).name() << endl;
}

//void g(int (&x)[3])
void g(int x[3])
{
    cout << typeid(x).name() << endl;
    // [3] 是徒劳，因为退化问题，与 int x[], 或者 int* x 是一样的
}


int main()
{
    int* p;
    int q[] = {1,2,3};
    int a = 16;
    cout << typeid(p).name() << endl;
    cout << typeid(q).name() << endl;
    cout << typeid(a).name() << endl;
    g(q);
    f(q);
    return 0;
}
