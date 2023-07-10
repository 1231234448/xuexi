#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> a = {2,6,8,12,3,7,2,5,6,11,9,};
    sort(a.begin(), a.begin()+5);
    sort(a.begin()+5, a.end());
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    inplace_merge(a.begin(), a.begin()+5, a.end());
    cout << "\n";
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
