#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, string> a;
    a["xx1001"] = "zhang";
    a["xx1002"] = "wang";
    a["xx1003"] = "li";
    a["xx1004"] = "zhao";
    a["xx1005"] = "wang";

    multimap<string, string> b;
    for(auto i=a.begin(); i!=a.end(); ++i)
        b.insert(make_pair(i->second, i->first));

    cout << b.count("zhang") << endl;
    cout << b.count("wang") << endl;
    auto it = b.find("wang");
    while(it != b.end() && it->first == "wang"){
        cout << it->second << endl;
        ++it;
    }

    return 0;
}
