#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

bool ok(array<int,8> a)
{
    for(auto i=a.begin(); i!=a.end(); ++i){
        for(auto j=i-1; j>=a.begin(); --j){
            if(i-j==abs(*i-*j)) return false;
        }
    }
    return true;
}

void show(array<int,8> a)
{
    for_each(a.begin(), a.end(),
             [](int x){
        string s(8, '.');
        s[x] = '*';
        cout << s << endl;
    });
}

int main()
{
    array<int,8> a = {0,1,2,3,4,5,6,7};
    do{
        if(ok(a)) {
            show(a);
            break;
        }
    }while(next_permutation(a.begin(),a.end()));

    return 0;
}
