#include <iostream>
#include <sstream>

using namespace std;

int main()
{
//    string s = "12345";
//    char buf[100];
//    buf[s.copy(buf,99)] = '\0';
//    cout << buf << endl;

//    string s = "123";
//    int a = atoi(s.c_str());
//    cout << a << endl;

//    string s = "123";
//    stringstream ss;  // 操作类似于 cin, cout，只是针对串
//    int a;
//    ss << s;
//    ss >> a;
//    cout << a << endl;

    string s1 = "1234";
    string s2 = "ff";
    string s3 = "1010";
    string s4 = "0x7f";

    cout << stoi(s1) << endl;
    cout << stoi(s2,NULL,16) << endl;
    cout << stoi(s3,NULL,2) << endl;
    cout << stoi(s4,NULL,0) << endl;

    return 0;
}

