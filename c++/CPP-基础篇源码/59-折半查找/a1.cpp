#include <iostream>

using namespace std;

// 查找 >x 的第一个位置，没有则返回 end+1
int* find_pos(int* begin, int* end, int x)
{
    if(begin==end){
        if(*begin>x) return begin;
        return begin+1;
    }

    int m = (end-begin)/2;
    if(begin[m]>x)
        find_pos(begin, begin+m, x);
    else
        find_pos(begin+m+1, end, x);
}

//插入排序
void insert_sort(int* data, int N)
{
    int* p = data+1;
    while(p<data+N){
        int* q = find_pos(data, p-1, *p);
        if(q!=p){
            int t = *p;
            memmove(q+1,q,(p-q)*sizeof(int));  // overlap 移动！！
            *q = t;
        }
        p++;
    }
}

int main()
{
    int data[] = {3,16,29,19,3,8,15,33,19,21,19,6,5,17,3};

    insert_sort(data, sizeof(data)/4);

    for(int i=0; i<sizeof(data)/4; i++) cout << data[i] << " ";
    cout << endl;

    return 0;
}
