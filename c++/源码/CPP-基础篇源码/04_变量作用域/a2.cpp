#include <iostream>
using namespace std;

//int a = 100;
//int b = 200;
//int c;
// c = a + b;  // 编译错误！

int main()
{
    int a = 5, b = 8;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << "," << b << endl;
    return 0;
}
