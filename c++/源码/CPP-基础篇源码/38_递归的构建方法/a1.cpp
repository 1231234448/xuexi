#include <iostream>

using namespace std;

// m 个球中，取 n 个
int qu(int m, int n)
{
    if(n<0) return 0;
    if(m==n) return 1;
    return qu(m-1, n-1) + qu(m-1, n);
}

int main()
{
    cout << qu(5,3) << endl;
    return 0;
}
