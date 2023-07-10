#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
    vector<int> a;
    for(int i=1; i<=10; i++) a.push_back(i);

    for(auto i=a.begin(); i!=a.end();){
        if(*i % 2 == 0)
            a.erase(i);
        else
            ++i;
    }

    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
