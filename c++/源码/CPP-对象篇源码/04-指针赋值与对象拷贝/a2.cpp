#include <iostream>

using namespace std;

class MyA{
public:
    int x;
    int y;
    void show(){
        printf("(%d,%d)\n", x, y);
    }
};

int main()
{
    MyA* p = new MyA{10,20};
    MyA q = *p;
    p->x++;
    q.show();

    delete p;

    return 0;
}
