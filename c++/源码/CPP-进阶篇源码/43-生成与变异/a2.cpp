#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

int main()
{
    int a[10];
    int i = 0;
    generate(a, a+10,
             [&i](){ ++i; return i*i; });
    copy(a,a+10,ostream_iterator<int>(cout," "));
    return 0;
}
