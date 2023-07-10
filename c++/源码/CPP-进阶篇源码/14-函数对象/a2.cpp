#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class MyF{
public:
    MyF():sum(0){}
    void operator() (int x) { sum += x; }
    int get_sum() { return sum; }
private:
    int sum;
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    MyF a = for_each(v.begin(), v.end(), MyF());
    cout << a.get_sum() << endl;


    return 0;
}
