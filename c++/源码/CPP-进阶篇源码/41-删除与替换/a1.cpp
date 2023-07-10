#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> a = {2,5,-3,0,19,-8,-6,2,-1,12,-7};
    auto i = remove_if(a.begin(), a.end(), bind2nd(less<int>(),0));
    cout << (i-a.begin()) << endl;
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
