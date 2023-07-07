#include <iostream>
#include <limits>
using namespace std;


int main()
{
    cout << std::numeric_limits<int>::max() << endl;
    cout << std::numeric_limits<unsigned>::max() << endl;
    cout << std::numeric_limits<long long int>::max() << endl;

    return 0;
}
