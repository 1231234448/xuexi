#include <iostream>

using namespace std;

class Circle{
public:
    Circle(){
        cout << "init Circle() (0,0,1)" << endl;
    }
//    Circle(int x, int y){
//        cout << "init circle(int, int)" << endl;
//    }
    Circle(int x, int y, int r=8){
        Circle();
        cout << "init circle(int, int, int)" << endl;
    }
    Circle(Circle* x){
        cout << "init circle(Circle*)" << endl;
    }
};

int main()
{
    Circle a(10,10);
    Circle b(&a);
    return 0;
}
