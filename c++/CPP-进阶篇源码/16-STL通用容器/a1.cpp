#include <iostream>

using namespace std;

int main()
{
    string s = "abcdefg";
    for(auto i=s.begin(); i!=s.end(); ++i){
        cout << *i << endl;
        if(*i=='g') s.erase(i);
    }
    cout << s << endl;
    return 0;
}
