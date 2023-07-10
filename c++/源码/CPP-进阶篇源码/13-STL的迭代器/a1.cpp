#include <iostream>

using namespace std;

int main()
{
//    string s = "1234567";
//    for(auto i = s.rbegin(); i != s.rend(); ++i){
//        cout << *i << endl;
//    }

    string s = "1234567";
    for(string::const_reverse_iterator i = s.crbegin();
    i != s.crend(); ++i){
        cout << *i << endl;
    }
    return 0;
}
