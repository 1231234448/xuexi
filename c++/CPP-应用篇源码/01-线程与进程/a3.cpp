#include <iostream>
#include <thread>

using namespace std;

int main()
{
//    cout << "begin" << endl;
//    this_thread::sleep_for(chrono::seconds(5));
//    cout << "end" << endl;

    cout << "begin" << endl;
    chrono::system_clock::time_point p =
            chrono::system_clock::now() +
            chrono::seconds(5);
    this_thread::sleep_until(p);
    cout << "end" << endl;
    return 0;
}
