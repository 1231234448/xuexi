#include <iostream>
#include <memory>

using namespace std;

struct MyA{
    ~MyA(){ cout << "MyA destroy..." << endl; }
    void f() { cout << "MyA.f()..." << endl; }
};

void g(unique_ptr<MyA> r){ }

int main()
{
    unique_ptr<MyA> p(new MyA);
    p->f();

//    unique_ptr<MyA> q;
//    q = p;  // 编译出错
//    q = move(p);

    g(move(p));

    return 0;
}
