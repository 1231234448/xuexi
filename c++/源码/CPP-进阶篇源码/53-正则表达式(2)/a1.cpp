#include <iostream>
#include <regex>

using namespace std;

int main()
{
//    regex re("\\d+");
//    smatch result;
//    string s = "abc123xyz7890-ttt";
//    auto it = s.cbegin();
//    auto end = s.cend();
//    while(regex_search(it, end, result, re)){
//        cout << result[0] << endl;
//        it = result[0].second;
//    }

    regex re("\\d+");
    cmatch result;
    const char* s = "abc123xyz7890-ttt";
    auto it = s;
    auto end = s + strlen(s);
    while(regex_search(it, end, result, re)){
        cout << result[0] << endl;
        it = result[0].second;
    }

    return 0;
}
