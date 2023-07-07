#include <iostream>
using namespace std;

//int a = 100;
//int b = 200;
//int c;
// c = a + b;  // 编译错误！

int main()
{
    int a = 5, b = 8;
    { int t = a; a = b; b = t; }
    cout << a << "," << b << endl;
    return 0;
}
