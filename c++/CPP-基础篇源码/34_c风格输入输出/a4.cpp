#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char buf[100];
    printf("your name? ");
    scanf("%[^\n]", buf);
    printf("hello, %s\n", buf);

    return 0;
}
