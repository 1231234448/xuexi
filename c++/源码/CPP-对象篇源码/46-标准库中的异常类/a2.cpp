#include <iostream>

using namespace std;

int main()
{
//    string a = "12345671234567";
//    cout << a.find("56") << endl;
//    cout << a.find("58") << endl;  // 返回 string::npos
//    // static const size_t npos = -1;
//    cout << a.find("56",7) << endl;  // 从 7 位置开始往后找

//    string s = "abcdefg";
//    string::iterator i = s.begin();
//    while(i!=s.end()){
//        cout << *i << endl;
//        i++;
//    }

    string s = "abcdefg";
    for(auto i=s.rbegin(); i!=s.rend(); i++){
        cout << *i << endl;
    }

    return 0;
}

