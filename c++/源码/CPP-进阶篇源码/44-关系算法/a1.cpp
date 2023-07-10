#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int next(int x)
{
    string s = to_string(x);
    while(s.length()<5) s.push_back('0');
    sort(s.begin(), s.end());
    int a = stoi(s);
    reverse(s.begin(), s.end());
    int b = stoi(s);
    return b - a;
}

vector<int> f(int x)
{
    vector<int> a;
    while(true){
        auto i = find(a.begin(), a.end(), x);
        if(i != a.end()){
            a.erase(a.begin(),i);
            return a;
        }
        a.push_back(x);
        x = next(x);
    }
}

int main()
{
    vector<int> da;
    for(int i=10000; i<=99999; i++) {
        vector<int> t = f(i);
        if(find(da.begin(), da.end(), t[0]) == da.end()){
            copy(t.begin(), t.end(),
                 back_insert_iterator<vector<int>>(da));
            da.push_back(-1);
        }
    }
    cout << count(da.begin(), da.end(), -1) << endl;
    copy(da.begin(), da.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
