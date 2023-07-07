#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;


int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    while(a.size()>1){
        rotate(a.begin(), a.begin()+1, a.end());
        rotate(a.begin(), a.begin()+1, a.end());
        rotate(a.begin(), a.begin()+1, a.end());
        a.pop_back();
    }
    cout << a[0] << endl;
    return 0;
}
