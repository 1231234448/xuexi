#include <iostream>
#include <thread>

using namespace std;

void f()
{
    for(int i=0; i<10; i++){
        cout << "thread: " << i << endl;
    }
}
int main()
{
    thread td(f);

    for(int i=0; i<10; i++){
        cout << "main...." << i << endl;
    }
    return 0;
}
