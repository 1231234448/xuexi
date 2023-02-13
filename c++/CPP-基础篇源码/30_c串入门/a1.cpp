#include <iostream>
using namespace std;

int main()
{
    char a = 'A';
    char* p = &a;  // p 与 int* 性质相同，本身并不是串
    char b[] = {'A', 0};  // b 是串，因为它所指向的区域，以0为结束符
    char c[] = {'A', 0, 'B', 'C'}; // c是串，且与b同
    cout << p << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}
