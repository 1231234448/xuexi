#include <iostream>
using namespace std;

int main()
{
    // 指针的本质就是一个整数，
    // 只不过，观念上，编译器认为它是某块数据的地址
    void *p  = (void *)1234567;
    cout << p << endl;
    cout << p+1 << endl;
    return 0;
}
