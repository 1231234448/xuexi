#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T, int N>
void mysort(T(&a)[N])
{
    sort(a, a+N, greater<T>());
}

template <typename T, int N>
void disp(T (&a)[N])
{
    copy(a, a+N, ostream_iterator<T>(cout, " "));
    cout << endl;
}

int main()
{
    int a[] = { 15, 22, 13, 28, 3, 16, 4, 27, 11 };
    mysort(a);
    disp(a);

    return 0;
}
