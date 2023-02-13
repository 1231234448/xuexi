#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string,int> a;
    a["zhang"] = 70;
    a["li"] = 85;
    a["wang"] = 99;
    a["zhang"] += 10;

    for(auto i=a.begin(); i!=a.end(); ++i)
        cout << i->first << ":" << i->second << endl;

    return 0;
}
