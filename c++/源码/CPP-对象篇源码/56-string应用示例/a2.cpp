#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main()
{
//    char buf[100] = " abcd  xyz    1234  ";
//    char* p = strtok(buf, " ");
//    while(p){
//        cout << p << endl;
//        p = strtok(NULL, " ");
//    }

    string s = "   abcd   ";
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ")+1);
    cout << s << endl;
    cout << s.length() << endl;

    return 0;
}

