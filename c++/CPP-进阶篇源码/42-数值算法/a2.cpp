#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

int main()
{
    int a[] = {1,2,3,4,5};
    int b[5];
    partial_sum(a, a+5, b);
    copy(b,b+5,ostream_iterator<int>(cout," "));
    return 0;
}
