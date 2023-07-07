#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex g1;

void f()
{
    g1.lock();
    for(int i=0; i<10; i++){
        if(i==6) throw -1;
        cout << this_thread::get_id() << ": " << i << endl;
    }
    g1.unlock();
}

int main()
{
    thread t1(f);
    thread t2(f);
    t1.join();
    t2.join();
    cout << "main end" << endl;
    return 0;
}
