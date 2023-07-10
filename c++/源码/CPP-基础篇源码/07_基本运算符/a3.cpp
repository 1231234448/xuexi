#include <iostream>
using namespace std;


int main()
{
    char x = 'r';
    char y = x - 32;
    cout << y << endl;

    char y1 = x - ('a' - 'A');
    cout << y1 << endl;

    return 0;
}
