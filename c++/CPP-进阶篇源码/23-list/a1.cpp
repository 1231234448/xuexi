#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

bool is_digit(const char& x)
{
    return x >= '0' && x <= '9';
}

int main()
{
//    list<int> a = {5,7,10,22,15,3,6,5,1,1,5};
//    a.sort();
//    a.unique();
//    copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout, " "));

//    list<int> a = {1,3,5,7,9};  // 已经有序
//    list<int> b = {2,2,6,10}; // 已经有序
//    a.merge(b);
//    copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout, " "));


//    list<int> a = {1,2,3,4,5};
//    list<int> b = {10,20,30,40};

//    auto i = a.begin();
//    advance(i,3);
//    a.splice(i, b);  // 也可以只剪切 b 的一部分

//    copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout, " "));
//    cout << endl;
//    copy(b.cbegin(), b.cend(), ostream_iterator<int>(cout, " "));
//    cout << endl;

//    list<int> a = {1,2,3,4,5};
//    auto i = a.begin();
//    advance(i,2);
//    a.splice(a.begin(), a, i, a.end());  // 3,4,5,1,2

    string s = "a1b2c33de4f";
    list<char> a(s.cbegin(), s.cend());

    a.remove_if(is_digit);

    copy(a.begin(), a.end(), ostream_iterator<char>(cout, " "));

    return 0;
}
