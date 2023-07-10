#include <iostream>

using namespace std;

struct Point{
    int x;
    int y;
};  // 新定义了一个类型，名字：Point，地位相当于：int

void show(const Point& pt)
{
    cout << "Point: (" << pt.x << "," << pt.y << ")";
    cout << endl;
}

void f(Point* t)
{
    t->x++;
    t->y++;
}

int main()
{
    Point a = Point{3,5};  //字面量生成“立即数”
    Point b = Point{10,20};  // 类似数组赋初值
    Point c = a;  // 拷贝每个成员的意思
    f(&a);
    show(a);

    return 0;
}
