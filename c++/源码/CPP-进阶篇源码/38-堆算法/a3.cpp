#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> a;
    int t[] = {3,8,2,9,11,4,6,13,7,1,10,12};
    for(int i=0; i<sizeof(t)/sizeof(int); i++)
        a.push(t[i]);
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl;

    return 0;
}
