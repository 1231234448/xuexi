#include <iostream>
using namespace std;

int main()
{
    int a = -25;
    unsigned char* p = (unsigned char *)&a;
    cout << hex << (int)p[0] << endl;
    cout << hex << (int)p[1] << endl;
    cout << hex << (int)p[2] << endl;
    cout << hex << (int)p[3] << endl;
    return 0;
}
