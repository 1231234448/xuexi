#include <iostream>
using namespace std;


int main()
{
    {
        int a[3] = {1,2,3};
        cout << a << endl;   // 它的值是多少？类型？等同不？
        cout << &a << endl;
        cout << &a[0] << endl;  // &(a[0])
    }
    {
        int a[3] = {1,2,3};
        cout << a << endl;
        cout << &a << endl;
        cout << a + 1 << endl;
        cout << &a + 1 << endl;
        cout << (a == &a) << endl;
    }

    return 0;
}
