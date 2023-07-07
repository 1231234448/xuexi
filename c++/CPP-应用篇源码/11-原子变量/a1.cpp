#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> sum{0};

void f(int x)
{
    for(int i=0; i<x; i++) sum++;
}

int main()
{
    auto t = clock();
    thread t1(f, 1000*1000);
    thread t2(f, 1000*1000);
    t1.join();
    t2.join();
    cout << sum << endl;
    t = clock() - t;
    cout << t << endl;
    return 0;
}
