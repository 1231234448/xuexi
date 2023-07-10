#include <iostream>

using namespace std;


class T{
public:
    int x;
    T(int x){ this->x = x; }
    ~T(){
        cout <<  x << " destroy..T" << endl;
    }
};


void f1(T a){}
void f2(T& a){}
T f3(){ return T(3); }


int main()
{
    T a(1);
    a = f3();
//    T a(1);
//    f1(a);
//    f2(a);
    return 0;
}
