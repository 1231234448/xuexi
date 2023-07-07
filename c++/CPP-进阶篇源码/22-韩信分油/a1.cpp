#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <array>

using namespace std;

template <int N>
struct Bottles{
    array<int,N> V;
    array<int,N> v;
    bool operator==(const Bottles& t) const {
        for(int i=0; i<N; i++) if(v[i] != t.v[i]) return false;
        return true;
    }
    // 从第 i 个瓶子倒入 第 j 个瓶子
    bool flow(int i, int j){
        if(i==j) return false;
        if(v.at(i)==0) return false; // 源瓶空
        if(v.at(j)==V.at(j)) return false; // 目标瓶满

        if(v[i] + v[j] < V[j]){
            v[j] += v[i];
            v[i] = 0;
        }
        else{

            v[i] -= V[j] - v[j];
            v[j] = V[j];
        }
        return true;
    }
    friend ostream& operator<<(ostream& os, const Bottles<N> t){
        cout << "(";
        for(int i=0; i<N; i++) cout << t.v[i] << " ";
        cout << ")";
        return os;
    }
};

template <int N>
bool ok(const Bottles<N>& bt, int goal)
{
    auto it = find(bt.v.cbegin(), bt.v.cend(), goal);
    return it != bt.v.cend();
}

template <int N>
bool fen(Bottles<N> bt, int goal)
{
    deque<Bottles<N>> da;  // 工作队列，执行BFS
    da.push_back(bt);

    vector<Bottles<N>> his;  // 记录所有已知的状态
    his.push_back(bt);

    while(true){
        int n = da.size();
        if(n==0) return false;
        for(int i=0; i<n; i++){
            auto t = da.front();
            if(ok(t, goal)) return true;
            da.pop_front();

            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++){
                    auto t2 = t;
                    if(!t2.flow(i,j)) continue;
                    if(find(his.cbegin(), his.cend(), t2) != his.cend()) continue;
                    cout << "?" << t2 << endl;
                    his.push_back(t2);
                    da.push_back(t2);
                }
        }
        cout << "?------------" << endl;
    }
}

int main()
{
    Bottles<3> bt;
    bt.V = {10,7,3};
    bt.v = {10,0,0};

    bool x = fen(bt,5);
    cout << x << endl;
    return 0;
}
