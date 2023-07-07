#include <iostream>

using namespace std;

// 平面直角坐标位置
class Point{
public:
    Point(){
        cout << "init point()" << endl;
        x = 0;
        y = 0;
    }
    Point(int x, int y){
        cout << "init point(x, y)" << endl;
        this->x = x;
        this->y = y;
    }
    void set(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getx() { return x; }
    int gety() { return y; }
private:
    int x;
    int y;
};

class Circle{
public:
    Circle(){
        cout << "init circle()" << endl;
        pt.set(0,0);
        r = 1;
    }
    Circle(int r){
        cout << "init circle(int)" << endl;
        Circle();
        this->r = r;
    }
    void show(){
        printf("circle: (%d,%d)%d\n", pt.getx(),pt.gety(),r);
    }
private:
    Point pt;  // 圆心
    int r;  // 半径
};

int main()
{
    //Circle a;
    Circle a(10);
    //a.show();
    return 0;
}
