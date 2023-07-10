#include <iostream>
using namespace std;

typedef int ITEM;
void swap(ITEM& a, ITEM& b){ ITEM t=a; a=b; b=t; }
void bubble_sort(ITEM* buf, int n,
                 int (*fp)(ITEM& a, ITEM& b) )
{
    for(int j=0; j<n-1; j++){
        for(int i=0; i<n-j-1; i++){
            if((*fp)(buf[i],buf[i+1])>0)
                swap(buf[i],buf[i+1]);
        }
    }
}
/////-----------------------
int f(int&a, int&b)
{
    return a%10 - b%10;
}
void show(int* buf, int n)
{
    for(int i=0; i<n; i++) cout << buf[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {4,17,2,19,9,28,31,22,10};
    bubble_sort(a,9,f);
    show(a,9);

    return 0;
}
