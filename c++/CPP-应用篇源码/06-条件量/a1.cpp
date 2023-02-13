#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

vector<int> vec;
mutex g1;

void f()
{
    g1.lock();
    for(int i=0; i<vec.size(); i++){
        cout << "thread f: " << vec[i] << endl;
    }
    g1.unlock();
}

int main()
{
    g1.lock();
    thread t1(f);
    for(int i=0; i<10; i++) vec.push_back(i*10);
    cout << "vec ready" << endl;
    g1.unlock();

    t1.join();

    return 0;
}
