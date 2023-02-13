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

    mtx_a.lock();
    cout << "mtx_a locked" << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    mtx_b.lock();
    cout << "mtx_a, mtx_b locked" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    mtx_b.unlock();
    mtx_a.unlock();

    cout << "f .. end" << endl;
}


void g()
{
    cout << "g ... begin" << endl;

    mtx_b.lock();
    cout << "mtx_b locked" << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    mtx_a.lock();
    cout << "mtx_a, mtx_b locked" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    mtx_a.unlock();
    mtx_b.unlock();

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
