#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    {
        int a = 97;
        printf("%d %X %c \n", a, a, a); // 97 61 a
        const char* p = "abc";
        printf("%s, %d, %x, %p\n", p, p, p, p);
    }
    {
        double a = 125.34567;
        printf("%f, %9.1f, %-9.1f, %09.1f \n", a, a, a, a);
    }
    return 0;
}
