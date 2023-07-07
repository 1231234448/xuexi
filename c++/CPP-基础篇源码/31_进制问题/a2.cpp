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

void itobin(char* buf, int x)
{
    char* p = buf;
    do{
        *p++ = (x % 2) + '0';
        x /= 2;
    }while(x>0);
    *p = '\0';
    reverse(buf, p);
}

void itohex(char* buf, int x)
{
    char* p = buf;
    do{
        int t = x % 16;
        *p++ = t<10? t + '0' : t-10+'A';
        x /= 16;
    }while(x>0);
    *p = '\0';
    reverse(buf, p);
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
    itohex(buf, 255);
    cout << buf << endl;

    return 0;
}
