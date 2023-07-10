#include <iostream>
using namespace std;

int main()
{
    {
        int a[] = {-3,-2,-5,6,-1,7,8};
        int* p = a;
        while(*p <= 0) ++p;
        cout << *p << endl;
    }
    {
        int a[] = {1,2,3,4,5,-1,-2,-3};
        int b[10];
        int* p = a;
        int* q = b;
        while(*p >= 0) *q++ = *p++;
        cout << b[0] << b[1] << b[2] << endl;
    }
    {
        char* s = "abcd";
        char r[100];
        char* p = s;
        char* q = r;
        while(*q++ = *p++);
        cout << r << endl;
    }
    return 0;
}
