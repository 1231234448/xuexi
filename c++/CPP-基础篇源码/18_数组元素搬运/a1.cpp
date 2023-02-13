#include <iostream>

using namespace std;

void mycopy(int* dst, int* src, int* src_end)
{
    for(int* p = src; p < src_end; p++) *dst++ = *p;
}
void mycopy(int* dst, int* src, const int n)
{
    for(int i=0; i<n; i++) dst[i] = src[i];
}
void show(int* a, const int n)
{
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int a[] = {1,2,3,4,5};
    int b[] = {10,20,30,40,50,60};

    //mycopy(b+2, a+2, 3);
    mycopy(b+2, a+2, a+2+3);
    show(b,6);

    return 0;
}
