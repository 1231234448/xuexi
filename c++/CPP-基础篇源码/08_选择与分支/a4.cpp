#include <iostream>
using namespace std;


int main()
{
    int a = 5, b = 2, c = 8;
    if(a>b && a>c) cout << (b > c? b : c) << endl;
    if(b>a && b>c) cout << (a > c? a : c) << endl;
    if(c>a && c>b) cout << (a > b? a : b) << endl;

    return 0;
}
