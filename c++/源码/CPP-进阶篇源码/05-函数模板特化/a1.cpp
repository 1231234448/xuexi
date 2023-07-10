#include <iostream>
#include <cstring>

using namespace std;

template <class T>
bool eq(const T& a, const T& b)
{
    return a==b;
}

template<>
bool eq<char*>(char* const & p1, char* const & p2)
{
    cout << "eq...<>" << endl;
    return strcmp(p1,p2)==0;
}

bool eq(char* p1, char* p2)
{
    cout << "eq...normal" << endl;
    return strcmp(p1,p2)==0;
}

int main()
{
    int a = 10;
    cout << eq(a,5+5) << endl;
    char* p1 = "abc";
    char* p2 = "abc";
    char p3[] = "abc";
    cout << eq<>(p1, p2) << endl;
    cout << eq(p1, p3) << endl;
    return 0;
}
