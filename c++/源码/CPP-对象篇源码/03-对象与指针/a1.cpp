#include <iostream>

using namespace std;

class MyA
{
public:
    int x;
    char* p;
};

int main()
{
    MyA a;
    a.p = "zhangsan";
    a.x = 100;

    cout << sizeof(MyA) << endl;

    return 0;
}
