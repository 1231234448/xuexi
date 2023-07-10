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
    unique_lock<mutex> lck(mtx);
    while(!ready) cv.wait(lck);

    for(int i=0; i<vec.size(); i++){
        cout << "thread f: " << vec[i] << endl;
    }
}

int main()
{
    ready = false;
    thread t1(f);
    {
        unique_lock<mutex> lck(mtx);
        for(int i=0; i<10; i++) vec.push_back(i*10);
        ready = true;
    }
    cout << "vec ready" << endl;
    cv.notify_one();

    t1.join();
    return 0;
}
