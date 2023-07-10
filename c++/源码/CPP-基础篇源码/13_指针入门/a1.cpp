#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a = 5;
    int b = 8;
    swap(&a, &b);
    cout << a << "," << b << endl;

    return 0;
}
