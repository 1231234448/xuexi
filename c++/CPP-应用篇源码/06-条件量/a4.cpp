#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

using namespace std;

vector<int> vec;
mutex mtx;
condition_variable cv;
bool ready;

void f()
{
    {
        unique_lock<mutex> lck(mtx);
        while(!ready) cv.wait(lck);
    }

    for(int i=0; i<vec.size(); i++){
        cout << "thread ";
        cout << this_thread::get_id() << " :";
        cout << vec[i] << endl;
    }
}

int main()
{
    ready = false;
    thread t1(f);
    thread t2(f);
    {
        unique_lock<mutex> lck(mtx);
        for(int i=0; i<10; i++) vec.push_back(i*10);
        ready = true;
        cout << "vec ready" << endl;
    }
    cv.notify_all();
    t1.join();
    t2.join();
    return 0;
}
