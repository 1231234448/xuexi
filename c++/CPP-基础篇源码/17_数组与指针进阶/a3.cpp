#include <iostream>
using namespace std;


int main()
{
    int a;
    int* p = &a; cout << p << endl;
    p++; cout << p << endl;
    char b;
    char* q = &b; cout << (int)q << endl;
    q++; cout << (int)q << endl;

    return 0;
}
