#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> a = {2,6,8,12,3,7,2,5,6,11,9,};
    auto it = partition(a.begin(), a.end(), [](int x){
        return x % 2 == 0;
    });
    cout << (it-a.begin()) << endl;
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
