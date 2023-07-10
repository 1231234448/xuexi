#include <iostream>
using namespace std;

void f(const char* s)
{
    cout << s << endl;
}
void g(char* s)
{
    cout << s << endl;
}

int main()
{
    f("abc");
    g("abc");  // warning!

    return 0;
}
