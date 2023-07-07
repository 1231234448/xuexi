#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int sum = 0;
mutex g1;
void f(int x)
{
    unique_lock<mutex> uk(g1, defer_lock);
    for(int i=0; i<1000 * 10000; i++) {
        while(!uk.try_lock()){
            cout << this_thread::get_id();
            cout << " lock fail.." << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        sum += x;
        uk.unlock();
    }
}
int main()
{
    sum = 0;
    thread t1(f, 1);
    thread t2(f, -1);
    t1.join(); t2.join();
    cout << sum << endl;

    return 0;
}
