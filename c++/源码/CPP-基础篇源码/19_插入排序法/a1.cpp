#include <iostream>


using namespace std;

int* find_pos(int* begin, int* end, int x)
{
    for(int* p = begin; p<end; p++){
        if(*p >= x) return p;
    }
    return NULL;
}

void mycopy(int* dst, int* src, int* src_end)
{
    if(dst==src) return;
    int n = src_end - src;
    if(dst>src)
        for(int i=n-1; i>=0; i--) dst[i] = src[i];
    else
        for(int i=0; i<n; i++) dst[i] = src[i];
}

void mysort(int* a, const int N)
{
    for(int*p=a; p<a+N; p++){
        int t = *p;
        int* q = find_pos(a, p, t);
        if(q!=NULL){
            mycopy(q+1, q, p);
            *q = t;
        }
    }
}

int main()
{ 
    const int N = 9;
    int a[N] = {6, 7, 8, 2, 5, 3, 1, 9, 4};
    mysort(a, N);

    for(int i=0; i<N; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
