#include <iostream>
#include <thread>

using namespace std;

int main()
{
    auto p1 = chrono::high_resolution_clock::now();
    for(int i=0; i<100; i++){
        cout << i << endl;
    }
    auto p2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> ela = p2 - p1;
    cout << "use: " << ela.count() << " ms" << endl;
    return 0;
}
