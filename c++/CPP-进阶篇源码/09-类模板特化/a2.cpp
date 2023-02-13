#include <iostream>

using namespace std;

template <typename T1, typename T2>
struct MyA{
    static void f() { cout << "normal" << endl; }
};

template <typename T1, typename T2>
struct MyA<T1*, T2*>{
    static void f() { cout << "<T1*, T2*>" << endl; }
};

template <typename T>
struct MyA<T,T>{
    static void f() { cout << "<T, T>" << endl; }
};

template <>
struct MyA<int*, int*>{
    static void f() { cout << "<int*, int*>" << endl; }
};

int main()
{
    MyA<int, double>::f();
    MyA<int*, double*>::f();
    MyA<int, int>::f();
    MyA<int*, int*>::f();

    return 0;
}
