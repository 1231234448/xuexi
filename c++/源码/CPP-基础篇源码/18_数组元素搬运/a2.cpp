#include <iostream>

using namespace std;

void put_tag(int* p, int* end)
{
    for(int*q = p + *p; q<end; q += *p) *q = -1;
}

int* next_pos(int* p, int* end)
{
    while(++p<end && *p <0);
    return p<end ? p : NULL;
}

int main()
{
    const int M = 10;  //第M个素数
    const int N = M * 20;  //需要筛选 N 个数字
    int a[N];  // 栈上的数据
    for(int i=0; i<N; i++) a[i] = i+2;

    int* p = a;  // 标尺，即将标记它的所有倍数
    while(p!=NULL){
        put_tag(p, a+N);
        p = next_pos(p, a+N);  // 指向下一个没有被划掉的数
    }

    int k = 0;
    for(int i=0; i<N; i++){
        if(a[i] > 0) k++;
        if(k==M){
            cout << a[i] << endl;
            break;
        }
    }

    return 0;
}
