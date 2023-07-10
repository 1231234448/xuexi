#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int mid(int a, int b, int c)
{
    // 我们心中的目标是： a <= b <= c
    if(a > b) swap(&a, &b);
    if(b > c) swap(&b, &c);
    if(a > b) swap(&a, &b);
    return b;
}

int main()
{
    int a=5,b=2,c=8;
    cout << mid(a,b,c) << endl;

    return 0;
}
