#include <iostream>
using namespace std;

class T{
public:
    T():x(100){}
    void f() const { cout << y << endl; }
    void g() {y++;}
private:
    const int x;
    int y;
};

int main()
{
    const T a;
    //a.g();  // g() 非const函数，不可调用
    const_cast<T&>(a).g(); //强制后，去掉了const约束
    return 0;
}
