#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx_a;
mutex mtx_b;

void f()
{
    cout << "f .. begin" << endl;
    lock(mtx_a, mtx_b);
    cout << "mtx_a, mtx_b locked" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    mtx_b.unlock();
    mtx_a.unlock();

    cout << "f .. end" << endl;
}


void g()
{
    cout << "g ... begin" << endl;
    lock(mtx_b, mtx_a);
    cout << "mtx_a, mtx_b locked" << endl;
    {
        lock_guard<mutex> lck1(mtx_a, adopt_lock);
        lock_guard<mutex> lck2(mtx_b, adopt_lock);
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "g ... end" << endl;
}

int main()
{
    thread t1(f);
    thread t2(g);
    t1.join();
    t2.join();
    return 0;
}
