#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    map<int,string> a;
    a[5] = "zhang";
    a[8] = "wang";
    a[99] = "newton";

    string s = "-->";
    for_each(a.begin(), a.end(),[s](pair<int,string> p){
        cout << p.first << s << p.second << endl;
    });
    return 0;
}
