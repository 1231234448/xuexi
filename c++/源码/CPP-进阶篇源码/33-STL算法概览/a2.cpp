#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <list>
using namespace std;

int main()
{
//    vector<int> a = {1,2,3,4,5,6,7,8};
//    copy(a.begin(), a.begin()+4, a.begin()+2);
//    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));

//    list<int> a = {1,2,3,4,5,6,7,8};
//    auto i2 = a.begin();
//    i2++; i2++;
//    auto i4 = i2;
//    i4++; i4++;
//    copy(a.begin(), i4, i2);
//    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));

    list<int> a = {1,2,3,4,5,6,7,8};
    auto i4 = a.begin();
    i4++; i4++; i4++; i4++;
    auto i6 = i4;
    i6++; i6++;
    copy_backward(a.begin(), i4, i6);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
