#include <iostream>

using namespace std;

void f(int p[][3], int n)
{
    for(int i=0; i<n; i++){
        p[i][0] *= p[i][0];
    }
}

int main()
{
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    f(a,3);
    cout << a[2][0];

    return 0;
}
