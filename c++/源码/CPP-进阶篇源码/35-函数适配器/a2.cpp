#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <functional>
using namespace std;

int main()
{
    vector<int> a = {1,2,31,45,5,16,7,28};
    auto i = find_if(a.begin(), a.end(),
                     bind2nd(greater<int>(),10));
    cout << *i << endl;

    return 0;
}
