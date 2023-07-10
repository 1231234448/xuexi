#include <iostream>
#include <array>
#include <iterator>
#include <iomanip>

using namespace std;

template <int M, int N>
void fill(array<array<int,N>,M>& da)
{
    struct{
        void next() { p = (p+1) % 4; }
        int i(){ return da[p][0]; }
        int j(){ return da[p][1]; }
        int da[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int p = 0;
    } dr;

    int i=0,j=0;
    for(int k=1; k<=M*N; k++){
        da[i][j] = k;
        try{
            if(da.at(i+dr.i()).at(j+dr.j())>0) throw 1;
        }catch(...){
            dr.next();
        }
        i += dr.i();
        j += dr.j();
    }
}

int main()
{
    const int M = 4;
    const int N = 5;
    array<array<int, N>,M> x;
    // 清零
    for(int i=0; i<x.size(); i++) x[i].fill(0);
    // 螺旋填充
    fill<M,N>(x);
    // 结果显示
    for(int i=0; i<x.size(); i++){
        for(int j=0; j<x[i].size(); j++)
            cout << setw(3) << x[i][j];
        cout << endl;
    }

    return 0;
}
