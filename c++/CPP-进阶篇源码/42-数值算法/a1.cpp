#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

int main()
{
    int a=5, b=8, c=4;
    cout << max(a,b) << endl;
    cout << min({a,b,c}) << endl;

    string x = "thisiacupofcoffeeplease";
    auto p = max_element(x.begin(), x.end());
    cout << *p << endl;
    return 0;
}
