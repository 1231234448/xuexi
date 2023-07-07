#include <iostream>
#include <memory>

using namespace std;

struct MyA{
    ~MyA(){ cout << "MyA destroy..." << endl; }
    void f() { cout << "MyA.f()..." << endl; }
};

void g(shared_ptr<MyA> r){ r->f(); }

int main()
{
    shared_ptr<MyA> p = make_shared<MyA>();
    shared_ptr<MyA> q = p;
    g(p);
    cout << p.use_count() << endl;  // 有引用计数的概念

    return 0;
}
