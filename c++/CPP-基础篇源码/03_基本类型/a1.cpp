#include <iostream>
using namespace std;


int main()
{
    int a;
    short int b;
    long int c;
    long d;
    long long e;

    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(e) << endl;

    {
        unsigned int a;
        int b;
        unsigned c;
        cout << sizeof(a) << sizeof(b) << sizeof(c) << endl;
    }

    return 0;
}
