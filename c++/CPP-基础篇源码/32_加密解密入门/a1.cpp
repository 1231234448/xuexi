#include <iostream>

using namespace std;

void encode(char* p, int k)
{
    while(*p){
        if(*p >= 'a' && *p <= 'z'){
            *p = (*p - 'a' + 26 + k) % 26 + 'a';
        }
        p++;
    }
}

int main()
{
    char buf[] = "I love beijing tian an men";
    encode(buf, 5);
    cout << buf << endl;
    encode(buf, -5);
    cout << buf << endl;
    return 0;
}
