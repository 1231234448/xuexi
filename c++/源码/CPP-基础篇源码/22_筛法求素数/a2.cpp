#include <iostream>

using namespace std;

// 把p指向位置数字的整数倍划去
void put_tag(int* p, int* end)
{
    for(int*q = p + *p; q<end; q += *p) *q = -1;
}
// 从当前位置找一个最靠近的没有划去的数字
int* next_pos(int* p, int* end)
{
    while(++p<end && *p <0);
    return p<end ? p : NULL;
}
// 取得第 x 个素数
int get_nth(int x)
{
    const int N = x * 20;  //需要筛选 N 个数字
    int* a = new int [N];  // 堆上分配
    for(int i=0; i<N; i++) a[i] = i+2;  //初始化

    int* p = a;  // 标尺，即将标记它的所有倍数
    while(p!=NULL){
        put_tag(p, a+N);
        p = next_pos(p, a+N);  // 指向下一个没有被划掉的数
    }

    int t = -1;
    for(int i=0; i<N; i++){
        if(a[i] > 0) x--;
        if(x==0) {
            t = a[i];
            break;
        }
    }

    delete [] a;
    return t;
}

int main()
{
    cout << get_nth(5) << endl;
    return 0;
}
