#include <iostream>
using namespace std;

template <typename T>
void swap1(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

int main()
{
    int a=5,b=8;
    swap1<int>(a,b);
    //swap1(a,b);
    cout << a << "," << b << endl;

    return 0;
}
