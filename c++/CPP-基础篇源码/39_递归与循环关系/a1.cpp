#include <iostream>

using namespace std;

int mystrlen(const char* s)
{
    if(*s=='\0') return 0;
    return 1 + mystrlen(s+1);
}

bool mystrstarts(char* buf, char* s)
{
    if(*s=='\0') return true;
    if(*buf=='\0') return false;
    if(*s != *buf) return false;
    return mystrstarts(buf+1,s+1);
}

char* mystrstr(char* buf, char* s)
{
    if(*s=='\0') return buf;
    if(*buf=='\0') return NULL;
    if(mystrstarts(buf, s)) return buf;
    return mystrstr(buf,s);
}

int main()
{
    cout << mystrstr("abc123defg12345xyz", ";';") << endl;
    return 0;
}
