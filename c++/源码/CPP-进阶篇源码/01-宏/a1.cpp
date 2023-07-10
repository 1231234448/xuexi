#include <iostream>
#define LOG(x) cout << (x) << endl;
//#define LOG(x)

using namespace std;


#define SWAP(a,b) {int t=a; a=b; b=t; }

#define MAX(a,b) \
    ({ typeof(a) _a = (a); \
       typeof(b) _b = (b); \
     _a > _b ? _a : _b; })

int main()
{
    cout << "normal" << endl;
    LOG("only for debug...")

    int a=5,b=8;
    SWAP(a,b)
    cout << a << "," << b << endl;

    cout << MAX(2+3,4*5) << endl;

    return 0;
}

