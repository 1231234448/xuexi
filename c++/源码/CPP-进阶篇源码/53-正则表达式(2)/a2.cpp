#include <iostream>
#include <regex>

using namespace std;

int main()
{
    regex re("(\\d{4})-(\\d{2})-(\\d{2})");
    string s = "xyz 2030-05-14 thaisanewday";
    smatch result;
    if(regex_search(s,result,re)){
        cout << result[0] << endl;
        cout << result[1] << endl;
        cout << result[2] << endl;
        cout << result[3] << endl;
    }
    return 0;
}
