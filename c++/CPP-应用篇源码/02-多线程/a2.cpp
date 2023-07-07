#include <iostream>
#include <thread>

using namespace std;

void f()
{
    cout << "void f() .." << endl;
}
struct F{
    F(int a):x(a){}
    void operator()(){
        cout << "F::operator() " << x << endl;
    }
    void f(){
        cout << "member f " << x << endl;
    }
    int x;
};

int main()
{
    thread t1(f);
    thread t2(F(20));
    thread t3([](){cout << "noname func" << endl; });
    F a(10);
    thread t4(F::f, &a);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
