#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stringstream ss;
    ss << "1 2 3" << "\n";
    ss << "4 5";
    streambuf* old = cin.rdbuf(ss.rdbuf());

    int a = 0;
    int t;
    while(cin >> t) a += t;
    cout << a << endl;

    cin.rdbuf(old);

    return 0;
}
