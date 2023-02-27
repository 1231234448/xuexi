#include <iostream>
using namespace std;

int main()
{
    long long int  n,m=0; //使用long long int 防止用户输入数字过大
    cin >> n ;
    for(;n!=0;n/=10)
        m=m*10+n%10;
    cout << m ;
    return 0;
}
3
