#include <iostream>
using namespace std;

bool is_prime(int x)
{
    for(int i=2; i<x; i++) if(x % i == 0) return false;
    return true;
}
int main()
{
    for(int n=2; n<100; n++)
        if(is_prime(n)) cout << n << " ";
    cout << endl;
    return 0;
}
