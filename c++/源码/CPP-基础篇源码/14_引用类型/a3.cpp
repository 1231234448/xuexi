#include <iostream>
using namespace std;

int mydiv(int x, int y, int& shang, int& yu)
{
    if(y==0) return -1;
    shang = x / y;
    yu = x % y;
    return 0;
}

int main()
{
    int a, b;
    mydiv(8,5,a,b);
    cout << a << "," << b << endl;

    return 0;
}
