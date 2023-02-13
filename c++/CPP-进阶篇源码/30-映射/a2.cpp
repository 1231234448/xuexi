#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N = 10;  // 参加约瑟夫环的人数

    map<int,int> da;
    for(int i=1; i<=N; i++) da[i] = i + 1;
    da[N] = 1;

    int k = 1; // 当前持有令牌
    while(da[k]!=k){
        k = da[k];
        da[k] = da[da[k]];
        k = da[k];
    }

    cout << k << endl;

    return 0;
}
