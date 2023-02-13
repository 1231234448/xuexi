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
    for(int i=0; i<5; i++){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "main ... " << i << endl;
    }
    td.join();
    cout << "main end" << endl;

    return 0;
}
