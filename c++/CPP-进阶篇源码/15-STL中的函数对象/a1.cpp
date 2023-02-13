#include <iostream>
#include <algorithm>

using namespace std;

int add(int a, int b){ return a + b; }

struct MyF{
    int operator() (int a, int b){ return a*b; }
};
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    const int N = sizeof(a)/sizeof(int);
    cout << accumulate(a, a+N, 0, add) << endl;
    cout << accumulate(a, a+N, 1, MyF()) << endl;
    return 0;
}
