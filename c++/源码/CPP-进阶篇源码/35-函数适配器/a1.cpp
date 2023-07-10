#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <functional>
using namespace std;

bool f(set<int>& t, int x){
    return t.find(x) == t.end();
}

int main()
{
    set<int> a0 = {3,5,7};
    vector<int> a = {1,2,3,4,5,6,7,8};
    vector<int> b;
    copy_if(a.begin(), a.end(),
         back_insert_iterator<vector<int>>(b),
         bind1st(ptr_fun(f), a0));
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
