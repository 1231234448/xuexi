#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

int f(int x, int y)
{
    this_thread::sleep_for(chrono::seconds(2));
    return x * 10 + y;
}

int main()
{
    future<int> res = async(launch::async, f, 5, 8);
    //launch::deferred
    cout << "do other things" << endl;
    int r = res.get();
    cout << r << endl;
    return 0;
}
