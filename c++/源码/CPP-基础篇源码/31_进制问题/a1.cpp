#include <iostream>
#include <string.h>

using namespace std;

void reverse(char* begin, char* end)
{
    end--;
    while(begin < end){
        char t = *begin;
        *begin = *end;
        *end = t;
        begin++; end--;
    }
}

void itodec(char* buf, int x)
{
    char* p = buf;
    do{
        *p++ = (x % 10) + '0';
        x /= 10;
    }while(x>0);
    *p = '\0';
    reverse(buf, p);
}

int main()
{
    char buf[100];
    itodec(buf, 5301);
    cout << buf << endl;

    return 0;
}
