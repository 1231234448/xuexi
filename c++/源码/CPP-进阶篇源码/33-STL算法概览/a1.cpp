#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
using namespace std;

int main()
{
    vector<int> a = {1,2,3,4,4,5,6,7};
    array<int,4> b;
    copy(a.end()-4, a.end(), b.begin());
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
