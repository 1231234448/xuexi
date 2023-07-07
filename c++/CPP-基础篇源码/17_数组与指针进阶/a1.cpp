#include <iostream>
using namespace std;


int main()
{
    int a[3] = {1, 2, 3};
    int b[3] = {1, 2, 3};
    int* p = a;
    cout << (a == b) << endl; // == 的含义？
    cout << a << endl;
    cout << b << endl;
    cout << p << endl;
    a = b;  //编译不过去！
    cout << sizeof(a) << "," << sizeof(p) << endl;

    return 0;
}
