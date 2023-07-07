#include <iostream>

using namespace std;

int g_a = 0;
void add(int x)
{
    g_a += x;
}

int main()
{
    g_a = 0;
    for(int i=0; i<10; i++) add(i);
    cout << g_a << endl;

    return 0;
}
