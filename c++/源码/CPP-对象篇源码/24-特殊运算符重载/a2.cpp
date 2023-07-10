#include <iostream>
using namespace std;

// 用户类型
struct T{
    void f() { cout << "T::f()..." << endl; }
};

// 服务于 T 的智能指针
class PT{
public:
    PT(){ p = new T; }
    ~PT() {
        cout << "free T ..." << endl;
        delete p;
    }
    T* operator->(){ return p; }
private:
    T* p;
};

int main()
{
    PT p;
    p->f();
//    T* p = new T;
//    p->f();
    return 0;
}
