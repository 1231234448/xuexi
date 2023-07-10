#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void bubble_sort(int* a, const int N)
{
    for(int j=0; j<N-1; j++){
        for(int i=0; i<N-j-1; i++){
            if(a[i]>a[i+1]) swap(a[i],a[i+1]);
        }
    }
}

void show(int* a, const int N)
{
    for(int i=0; i<N; i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {3,5,9,2,1,4,6};
    const int N = sizeof(a) / sizeof(int);

    bubble_sort(a, N);

    show(a, N);

    return 0;
}
