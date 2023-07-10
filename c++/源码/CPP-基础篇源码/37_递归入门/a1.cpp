#include <iostream>

using namespace std;

long long fac(int x)
{
    if(x==0) return 1;
    return fac(x-1) * x;
}

long long fib(int x)
{
    if(x<2) return 1;
    return fib(x-1) + fib(x-2);
}

// 从 1 到 n 求和
int mysum(int x)
{
    if(x<1) return 0;
    return mysum(x-1) + x;
}

int main()
{
    cout << mysum(10000) << endl;
//    cout << fac(20) << endl;
//    cout << fib(45) << endl;
    return 0;
}
