#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
using namespace std;

int main()
{
    using namespace boost::multiprecision;

    cpp_int a = 0;
    cpp_int b = 1;
    int n = 100;
    for(int i=0; i<n; ++i){
        cpp_int c = a + b;
        a = b;
        b = c;
    }
    cout << a << endl;
}
