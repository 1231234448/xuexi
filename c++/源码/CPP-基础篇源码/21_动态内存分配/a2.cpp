#include <iostream>
using namespace std;

int* get_factor(int x)
{
    int n = 1; // 多分配一个用于结束标志
    for(int i=2; i<x; i++) if(x%i==0) n++;

    int* data = (int*)malloc(n * sizeof(int));
    n = 0;
    for(int i=2; i<x; i++) if(x%i==0) data[n++] = i;
    data[n] = -1;

    return data;
}

int main()
{

    int* a = get_factor(60);
    for(int* p=a; *p>0; p++) cout << *p << " ";
    cout << endl;
    free(a);

    return 0;
}
