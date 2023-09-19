#include <stdio.h>
struct node
{int a;
    long long b;
    char c;};
int main(int argc, char const *argv[]) {
    int a = sizeof(struct node);
    printf("a= ",a);
}
