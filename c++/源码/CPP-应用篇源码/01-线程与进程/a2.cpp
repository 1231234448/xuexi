#include <iostream>
#include <thread>

using namespace std;

void f()
{
    for(int i=0; i<10; i++){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "thread: " << i << endl;
    }
}
int main()
{
    thread td(f);

    for(int i=0; i<15; i++){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "main...." << i << endl;
    }
    return 0;
}
