#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char buf[100];
    printf("your name? ");
    scanf("%s", buf);
    printf("hello, %s\n", buf);
    return 0;
}
