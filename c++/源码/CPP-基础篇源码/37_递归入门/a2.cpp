#include <iostream>

using namespace std;

int feven(int n);  // 需要提前声明一下，与头文件原理类似
// 奇数步完成
int fodd(int n)
{
    if(n<=0) return 0;
    return feven(n-1) + feven(n-2);
}
// 偶数步完成
int feven(int n)
{
    if(n<0) return 0;
    if(n==0) return 1;
    return fodd(n-1) + fodd(n-2);
}

int main()
{
    cout << feven(5) << endl;
    return 0;
}
