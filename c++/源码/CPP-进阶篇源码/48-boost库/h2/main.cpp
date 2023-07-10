#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    using namespace boost::lambda;
    int a[] = {1,2,3,4,5};
    transform(a, a+5, a, (_1 * 2));
    for(auto i: a){
        cout << i << endl;
    }
    return 0;
}
