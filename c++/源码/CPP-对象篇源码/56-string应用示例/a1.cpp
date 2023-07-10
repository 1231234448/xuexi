#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string s = "    abc 1234  xyz    kkkk   ";
    int p1 = 0;
    while(1){
        int p2 = s.find(" ", p1);
        if(p2 == string::npos) {
            cout << s.substr(p1) << endl;
            break;
        }
        string s1 = s.substr(p1, p2-p1);
        if(!s1.empty())  cout << s1 << endl;
        p1 = s.find_first_not_of(" ", p2);
        if(p1 == string::npos) break;
    }

    return 0;
}

