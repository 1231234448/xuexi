#include <iostream>

using namespace std;

int main()
{
    string s1; // 空串
    string s2("1234567");  // 从 c-string 拷贝构造
    string s3(s2); // 拷贝构造
    string s4(s2,3); // s2 中从下标3开始
    string s5(s2,3,2); // s2 中从下标3开始，2个字符
    string s6(4,'x'); // 4 个 'x'
    string s7(s2.end()-3,s2.end()); // 迭代器区间，最后3个char

    cout << s1.length() << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;

    return 0;
}

