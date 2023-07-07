#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

template <class T, int N>
void print_array(T (&x)[N])
{
    for(int i=0; i<N; i++) cout << x[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {1,2,3,4,5};
    char* b[] = {"abc", "hah..", "123"};
    print_array(a);
    print_array(b);

    return 0;
}
