#include <iostream>
#include <regex>

using namespace std;

int main()
{
    string  s = "abc123xyz456 kkk 1399 dfs gag 026";
    regex re("\\d+");
    auto i = sregex_iterator(s.begin(), s.end(), re);
    auto end = sregex_iterator();
    while(i != end){
        cout << i->str() << endl;
        ++i;
    }

    return 0;
}
