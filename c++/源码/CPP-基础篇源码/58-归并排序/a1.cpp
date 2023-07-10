#include <iostream>

using namespace std;

// dst: 目标区，有足够空间； src , n : 源数据区
void merge_(int* dst, int* src, int n)
{
    if(n==1){
        *dst = *src;
        return;
    }

    int m = n / 2;  // 前半部分可能略小
    merge_(src, dst, m);
    merge_(src+m, dst+m, n-m);

    int* p = src;
    int* q = src + m;
    while(p < src+m && q < src+n){
        if(*p <= *q)
            *dst++ = *p++;
        else
            *dst++ = *q++;
    }

    if(p<src+m) memcpy(dst, p, (src+m-p)*sizeof(int));
    if(q<src+n) memcpy(dst, q, (src+n-q)*sizeof(int));
}

// 原地排序
void merge_sort(int* data, int N)
{
    int* buf = new int [N];
    memcpy(buf, data, N*sizeof(int));
    merge_(data, buf, N);
    delete [] buf;
}


int main()
{
    int data[] = {3,16,29,3,8,15,33,21,19,6,5,17,3};

    merge_sort(data, sizeof(data)/4);

    for(int i=0; i<sizeof(data)/4; i++) cout << data[i] << " ";
    cout << endl;

    return 0;
}
