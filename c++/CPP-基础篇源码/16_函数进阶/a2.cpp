#include <iostream>

using namespace std;

void f(int* a, const int N, int** p, int** q)
{
    for(int i=0; i<N; i++){
        if(a[i]<0) {
            *p = &a[i];
            break;
        }
    }

    for(int i=N-1; i>=0; i--){
        if(a[i]<0){
            *q = &a[i];
            break;
        }
    }
}

int main()
{
    int a[] = {3, 5, -3, 9, -5, 2, 1, -1, -2, 4, 6};
    const int N = sizeof(a) / sizeof(int);
    int *p, *q;
    f(a, N, &p, &q);

    cout << *p << ", " << *q << endl;

    return 0;
}
