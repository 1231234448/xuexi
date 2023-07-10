#include <iostream>
#include <cstring>
using namespace std;

int f(int x)
{
    if(x==0) return 0;
    return f(x-1)+1;
}

int main()
{
    cout << "begin" << endl;
    cout << f(1000 * 1000) << endl;
    cout << "end" << endl;
    return 0;
}
