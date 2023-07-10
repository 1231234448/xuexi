#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    int a[] = {2,5,12,8,6,3,13,25,119};
    const int n = sizeof(a)/sizeof(int);
    sort(a, a+n);
    copy(a, a+n, ostream_iterator<int>(cout," "));
    cout << binary_search(a, a+n, 25) << endl;
    return 0;
}
