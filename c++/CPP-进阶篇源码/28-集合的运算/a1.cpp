#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    set<int> a = {1,2,3,4};
    set<int> b = {3,4,5,6};
    set<int> c;
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),
                     insert_iterator<set<int>>(c,c.begin()));
    copy(c.begin(), c.end(), ostream_iterator<int>(cout," "));
    return 0;
}
