#include <iostream>
using namespace std;

int main() {
    int a = 10;     // 定义一个整数变量a
    int* ptr = &a;  // 定义一个指向整数的指针ptr，并将a的地址赋值给ptr

    cout << a << endl;    // 输出a的值，输出结果为10
    cout << *ptr << endl; // 输出通过指针访问的值，输出结果也为10

    return 0;
}
