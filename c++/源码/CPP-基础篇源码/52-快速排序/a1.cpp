#include <iostream>

using namespace std;

void qsort(int* begin, int* end)
{
    if(begin>=end) return;

    int t = *begin;
    int* p = begin;
    int* q = end;

    while(true){
        while(p<q && *q>=t) q--;
        if(p==q) break;
        *p++ = *q;
        while(p<q && *p<t) p++;
        if(p==q) break;
        *q-- = *p;
    }

    *p = t;

    qsort(begin, q-1);
    qsort(q+1, end);
}

void show(int* data, int n)
{
    for(int i=0; i<n; i++) cout << data[i] << " ";
    cout << endl;
}

int main()
{
    int data[] = {5,12,6,25,2,33,14,6,49,15,17,28,4,2,13,31};
    const int n = sizeof(data)/sizeof(int);

    qsort(data, data+n-1);
    show(data, n);

    return 0;
}
