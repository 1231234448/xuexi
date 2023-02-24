#include <iostream>
using namespace std;

int main()
{
    long long int  n; //使用long long int 防止用户输入数字过大
    cin >> n ;
    for(n;n!=0;n/=10)
    if(n==0){
    n=n;
    break;
    }
    else{
    cout << n%10 ;
    }
    
cout << endl ;
}
