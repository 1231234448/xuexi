#include <iostream>

using namespace std;

enum DIR{
    NORTH, EAST, SOUTH, WEST
};

struct Point{
    int x;
    int y;
    Point(){
        x = 0;
        y = 0;
    }
    void show(){
        printf("(%d,%d)", x, y);
    }
};

class Robot{
public:
    Robot(){
        dir = NORTH;
    }
    Robot& go(int step){
        switch (dir) {
        case NORTH:
            pt.y += step;
            break;
        case EAST:
            pt.x += step;
            break;
        case SOUTH:
            pt.y -= step;
            break;
        case WEST:
            pt.x -= step;
            break;
        }
        return *this;
    }
    Robot& left(){ dir = (DIR)((dir-1+4)%4); return *this; }
    Robot& right(){ dir = (DIR)((dir+1)%4); return *this; }
    void show() {
        pt.show(); cout << " ";
        switch (dir) {
        case NORTH:
            cout << "north";
            break;
        case EAST:
            cout << "east";
            break;
        case SOUTH:
            cout << "south";
            break;
        case WEST:
            cout << "west";
        }
        cout << endl;
    }
    void reset(){
        pt.x = 0; pt.y = 0;
        dir = NORTH;
    }
private:
    Point pt;  //当前坐标
    DIR dir;  // 朝向
};

int main()
{
    Robot a;
    a.go(5);
    a.right();
    a.go(10);
    a.left().left().go(20);
    a.show();
    a.reset();
    a.show();
    return 0;
}
