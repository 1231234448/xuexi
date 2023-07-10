#include <iostream>

using namespace std;

bool is_prime(int x)
{
    for(int i=2; i<x; i++) if(x%i==0) return false;
    return true;
}


int main()
{
    for(int i=2; i<1000; i++) if(is_prime(i)) cout << i << " ";
    cout << endl;

    return 0;
}
