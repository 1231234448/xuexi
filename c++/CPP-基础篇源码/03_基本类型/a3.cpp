#include <iostream>
#include <limits>
using namespace std;


int main()
{
    typedef long long int LL;
    LL a = std::numeric_limits<LL>::max();
    a++;
    cout << a << endl;
    cout << std::numeric_limits<LL>::min();

    return 0;
}
