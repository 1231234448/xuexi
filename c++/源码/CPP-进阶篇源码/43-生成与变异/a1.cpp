#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

int main()
{
//    vector<int> a = {1,2,3,4,5};
//    int sum = 0;
//    for_each(a.begin(), a.end(),
//             [&sum](int x){ sum += x; });
//    cout << sum << endl;

    vector<int> a = {1,2,3,4,5};
    string sum;
    for_each(a.begin(), a.end(),
             [&sum](int x){ sum = sum + to_string(x) + ","; });
    cout << sum << endl;
    return 0;
}
