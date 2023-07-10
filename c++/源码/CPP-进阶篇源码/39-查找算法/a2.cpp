#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {1,2,3,4,1,2,3,4,5,6,7,8,4,5,6,7};
    vector<int> b = {4,5,6};
    auto i = search(a.begin(), a.end(), b.begin(), b.end());
    cout << (i!=a.end()) << endl;

    return 0;
}
