#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

using namespace std;

int main()
{
    deque<int> a;
    int N = 10;
    for(int i=1; i<=N; i++) a.push_back(i);
    while(a.size()>1){
        a.push_back(a.front());
        a.pop_front();
        a.push_back(a.front());
        a.pop_front();

        a.pop_front();
    }
    cout << a[0] << endl;
    return 0;
}
