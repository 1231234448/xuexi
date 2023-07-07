#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex g1;

void f()
{
    lock_guard<mutex> lg(g1);
    for(int i=0; i<10; i++){
        if(i==6) throw -1;
        cout << this_thread::get_id() << ": " << i << endl;
    }
}

int main()
{
    thread t1(f);
    thread t2(f);
    t1.detach();
    t2.detach();

    this_thread::sleep_for(chrono::seconds(1));
    cout << "main end" << endl;
    return 0;
}
