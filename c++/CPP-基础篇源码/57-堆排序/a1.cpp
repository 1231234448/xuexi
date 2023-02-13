#include <iostream>

using namespace std;

inline swap(int&a, int& b){ int t=a; a=b; b=t; }
// 大顶堆调整
// 堆数据：data,n   // k: 当前要调整的堆顶
void adj(int* data, int n, int k)
{
    int l = k * 2 + 1;
    int r = l + 1;
    if(l >= n) return;
    if(r >= n){
        if(data[l] >= data[k]) swap(data[l], data[k]);
        return;
    }

    int s = (data[l] > data[r])? l : r;
    if(data[s] >= data[k]){
        swap(data[s], data[k]);
        adj(data, n, s);
    }
}

// 原地堆排序
void heap_sort(int* data, const int N)
{
    // 建立大顶堆
    for(int i=N/2; i>=0; i--) adj(data, N, i);
    // 堆顶输出到尾部
    int* p = data + N - 1;
    while(p!=data){
        swap(*data, *p);
        adj(data, p-data, 0);
        p--;
    }
}

int main()
{
    int data[] = {3,16,29,3,8,15,88,15,33,21,8,19,6,8,5,17,3};
    heap_sort(data, sizeof(data)/4);

    for(int i=0; i<sizeof(data)/4; i++) cout << data[i] << " ";
    cout << endl;

    return 0;
}
