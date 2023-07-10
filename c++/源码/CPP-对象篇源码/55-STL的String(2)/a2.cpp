#include <iostream>
#include <sstream>

using namespace std;

int main()
{
//    char buf[100];
//    itoa(255,buf,16);
//    cout << buf << endl;

//    char buf[100];
//    sprintf(buf, "%04x", 255);
//    cout << buf << endl;  // 00ff

    stringstream ss;
    string s;
    ss << hex << 255;
    ss >> s;
    cout << s << endl;

    return 0;
}

