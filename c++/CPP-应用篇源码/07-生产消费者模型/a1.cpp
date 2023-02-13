#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <ctime>  // srand

using namespace std;

queue<int> Q;
mutex mtx;
condition_variable cv_emp, cv_ful;

// consumer 消费者
void f1()
{
    srand(time(0));
    unique_lock<mutex> lck(mtx, defer_lock);
    while(1){
        lck.lock();
        while(Q.empty()) cv_emp.wait(lck);
        cout << this_thread::get_id();
        cout << " consum " << Q.front() << endl;
        Q.pop();
        if(Q.size()<=10) cv_ful.notify_all();
        lck.unlock();

        int t = rand()%1000;
        this_thread::sleep_for(chrono::milliseconds(t));
    }
}
// producer 生产者
void f2()
{
    srand(time(0));
    unique_lock<mutex> lck(mtx, defer_lock);
    for(int i=0; i<30; i++){
        lck.lock();
        while(Q.size()>10) cv_ful.wait(lck);
        cout << this_thread::get_id();
        cout << " produce " << i << endl;
        Q.push(i);
        cv_emp.notify_all();
        lck.unlock();

        int t = rand()%1000;
        this_thread::sleep_for(chrono::milliseconds(t));
    }
}

int main()
{
    thread t1[3], t2[3];
    for(int i=0; i<3; i++) t1[i] = thread(f1); //消费者
    for(int i=0; i<3; i++) t2[i] = thread(f2); //生产者
    for(int i=0; i<3; i++) t1[i].join();
    for(int i=0; i<3; i++) t2[i].join();
    return 0;
}