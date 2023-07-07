#include <iostream>
#include <thread>

using namespace std;

void g()
{
    thread_local int x = 0;
    x++;
    cout << x << endl;
}

void f()
{
    for(int i=0; i<10; i++) g();
}

int main()
{
    thread t1(f);
    thread t2(f);
    t1.join();
    t2.join();
    return 0;
}
