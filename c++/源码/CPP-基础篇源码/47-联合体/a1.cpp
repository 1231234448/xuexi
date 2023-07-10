#include <iostream>

using namespace std;

// 平面直角坐标上的点
struct Point{
    int x;
    int y;
};
// 圆
struct Circle{
    Point pt;  //圆心
    int r;  // 半径
};
// 矩形
struct Rect{
    Point pt1; // 左上角
    Point pt2; // 右下角
};
// 枚举图形的种类
enum ShapeKind{
    CIRCLE, RECT, TRIANGLE
};
// 图形
struct Shape{
    ShapeKind tag;
    union {
        Circle circle;
        Rect rect;
    };
};


int main()
{
    Shape a;
    a.tag = CIRCLE;
    a.circle.pt = Point{5,5};
    a.circle.r = 10;
    // 使用 a：
    switch (a.tag) {
    case CIRCLE:
        cout << a.circle.r << endl;
        break;
    default:
        break;
    }

    // 进一步的处理 ....
    return 0;
}
