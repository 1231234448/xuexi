#include <iostream>
using namespace std;

struct Shape{
    Shape(){ cout << "create Shape" << endl; }
    virtual ~Shape() { cout << "destroy Shape" << endl; }
};
struct Circle:Shape{
    Circle(){ cout << "create Circle" << endl; }
    virtual ~Circle(){ cout << "destroy Circle" << endl; }
};
struct Rect:Shape{
    Rect(){ cout << "create Rect" << endl; }
    virtual ~Rect(){ cout << "destroy Rect" << endl; }
};
struct Triangle:Shape{
    Triangle(){ cout << "create Triangle" << endl; }
    virtual ~Triangle(){ cout << "destroy Triangle" << endl; }
};
int main()
{
    Shape* x[3];
    x[0] = new Circle();
    x[1] = new Rect();
    x[2] = new Triangle();

    for(int i=0; i<3; i++) delete x[i];

    return 0;
}
