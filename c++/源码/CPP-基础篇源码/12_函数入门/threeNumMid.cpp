#include <iostream>

using namespace std;


int max(int a, int b)
{
    return a>b? a : b;
}

int min(int a, int b)
{
    if(a<b) return a;
    return b;
}

int min(int a, int b, int c)
{
    return min(min(a,b),c);
}

int mid(int a, int b, int c)
{
    int x = max(a,b);
    int y = max(a,c);
    int z = max(b,c);
    return min(x,y,z);
}

int main()
{
    int a = 5, b = 2, c = 8;
    cout << mid(a,b,c) << endl;
    return 0;
}
