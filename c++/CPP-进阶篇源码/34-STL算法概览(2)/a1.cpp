#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <list>
#include <set>
using namespace std;

int main()
{
    set<int> a0 = {3,5,7};
    struct F{
        F(set<int> &t):s(t){};
        set<int> s;
        bool operator()(int x){
            return s.find(x) == s.end();
        }
    };
    vector<int> a = {1,2,3,4,5,6,7,8};
    vector<int> b;
    copy_if(a.begin(), a.end(),
         back_insert_iterator<vector<int>>(b), F(a0));
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
