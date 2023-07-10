#include <iostream>
#include <bitset>

using namespace std;

template <int N>
int su()
{
    bitset<N> da;
    da.set();
    da[0] = 0;
    da[1] = 0;
    for(int k=2; k<N; k++){
        if(da[k]==0) continue;
        int p = k + k;
        while(p<N){
            da[p] = 0;
            p += k;
        }
    }
    return da.count();
}

int main()
{
    cout << su<1000 * 1000>() << endl;
    return 0;
}
