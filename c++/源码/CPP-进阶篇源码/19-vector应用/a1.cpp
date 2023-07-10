#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>  VI;
typedef vector<VI> VVI;

// n: 带分解, h: 限高
VVI f(int n, int h)
{
    VVI rt;
    if(n==0){
        rt.push_back(VI());
        return rt;
    }

    for(int i=1; i<=n; i++){
        if(i>h) break;
        VVI t = f(n-i, i);
        for(auto k=t.cbegin(); k!=t.cend(); ++k){
            VI t2;
            t2.push_back(i);
            t2.insert(t2.end(),(*k).begin(), (*k).end());
            rt.push_back(t2);
        }
    }

    return rt;
}

int main()
{
    VVI a = f(6,6);
    for(int j=0; j<a.size(); j++){
        for(int i=0; i<a[j].size(); i++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
