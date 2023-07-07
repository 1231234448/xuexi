#include <iostream>

using namespace std;


int main()
{
//    freopen("d:\\out.txt", "w", stdout);
//    cout << "haha" << endl;
//    cout << 123 << endl;
    freopen("d:\\in.txt", "r", stdin);
    string s;
    while(getline(cin, s)){
        cout << s << endl;
    }

    return 0;
}
