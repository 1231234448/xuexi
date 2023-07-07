#include <iostream>

using namespace std;

template <typename T>
void swap1(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

struct Point{
    int x;
    int y;
    void show() { printf("(%d,%d)\n", x, y); }
};

int main()
{
//    int a=5,b=8;
//    swap1<int>(a,b);
//    //swap1(a,b);
//    cout << a << "," << b << endl;

    Point p1{1,2};
    Point p2{3,4};
    swap1(p1,p2);
    p1.show();
    p2.show();

    return 0;
}
