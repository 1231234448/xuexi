#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>

using namespace std;

int main()
{
    deque<int> a = {3,8,2,9,11,4,6,13,7,1,10,12};
    make_heap(a.begin(), a.end(), greater<int>());
    pop_heap(a.begin(), a.end(), greater<int>());
    pop_heap(a.begin(), a.end()-1, greater<int>());
    pop_heap(a.begin(), a.end()-2, greater<int>());
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
