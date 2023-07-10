#include <iostream>
#include <string.h>

using namespace std;

void show(int* a, int k)
{
    const int w = 50;
    char buf[200];
    char* p = buf;
    for(int i=0; i<k; i++){
        p += sprintf(p, "%3d ", a[i]);
    }
    int sp = (w - strlen(buf)) / 2;
    printf("%*s%s\n", sp, "", buf);
}

int main()
{
    int a[20];
    int k = 0;  // 当前有效数据个数
    for(int j=0; j<10; j++){
        int t0 = 0, t;
        for(int i=0; i<k; i++){
            t = a[i];
            a[i] += t0;
            t0 = t;
        }
        a[k++] = 1;
        show(a,k);
    }



    return 0;
}
