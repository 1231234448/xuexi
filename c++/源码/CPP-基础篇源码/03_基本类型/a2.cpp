#include <iostream>
#include <limits>
#include <math.h>
using namespace std;


int main()
{
    unsigned long long a =std::numeric_limits<long long int>::max();
    cout << a << endl;
    cout << log10(a) << endl;
    

    return 0;
}
