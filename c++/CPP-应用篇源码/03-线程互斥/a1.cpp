#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex g1;

void f()
{
    for(int i=0; i<10; i++){
        this_thread::sleep_for(chrono::milliseconds(500));
        g1.lock();
        cout << "thread: "
             << "<" << this_thread::get_id() << ">"
             << i << endl;
        g1.unlock();
    }
}
int main()
{
    thread t1(f);
    thread t2(f);
    t1.join();
    t2.join();

    return 0;
}
