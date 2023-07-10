#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    string s = "sothat";
    vector<char> a(s.begin(), s.end());
    sort(a.begin(), a.end());
    copy(a.begin(), a.end(), ostream_iterator<char>(cout," "));
    cout << endl;

    return 0;
}
