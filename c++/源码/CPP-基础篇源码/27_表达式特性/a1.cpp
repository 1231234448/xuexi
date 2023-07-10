#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 3;
    int x = a > 3 ? 0 : 1;  // 与下边的等价：
    if(a > b)
        x = 0;
    else
        x = 1;
    cout << x << endl;
    // 但是你无法这样写：
    // x = if(a>3) 0 else 1;
    return 0;
}
