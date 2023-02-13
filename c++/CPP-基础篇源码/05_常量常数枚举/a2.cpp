#include <iostream>
using namespace std;

int main()
{
    //int a = 365 * 24 * 60 * 60 * 1000;
    long long a = 365LL * 24 * 60 * 60 * 1000;
    cout << a << endl;
    int b = 254;
    cout << b << "," << hex << b << endl;

    const int MONDAY = 1;
    int c = MONDAY;
    int d = MONDAY;

    enum week{Mon, Tue, Wed, Thu, Fri, Sat, Sun} e;
    //e = 1; // 会报错
    e = Mon;
    cout << c << d << e << endl;


    return 0;
}
