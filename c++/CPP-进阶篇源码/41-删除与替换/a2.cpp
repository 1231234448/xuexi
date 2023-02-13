#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> a = {1,2,5,2,3,6,2,1,3,4,4};
    sort(a.begin(), a.end());
    auto i = unique(a.begin(), a.end());
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    a.resize(i-a.begin());
    cout << "\n";
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
