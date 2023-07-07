#include <iostream>
#include <regex>

using namespace std;

int main()
{
//    regex re("(\\d{4})-(\\d{2})-(\\d{2})");
//    string s = "xyz 2030-05-14 thaisanewday";
//    cout << regex_replace(s, re, "<***>") << endl;


    regex re("(\\d{4})-(\\d{2})-(\\d{2})");
    string s = "xyz 2030-05-14 thaisanewday";
    cout << regex_replace(s, re, "$2-$3-$1") << endl;


    return 0;
}
