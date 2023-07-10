#include <iostream>
using namespace std;

class Cnt{
public:
    Cnt(){ x=0; }
    Cnt& inc() { x++; return *this; }
    Cnt& dec() { x--; return *this; }
    int get() { return x; }

    Cnt& operator++(){ x++; return *this; }
    Cnt operator++(int){ Cnt t = *this; x++; return t; }
private:
    Cnt(int a){ x = a; }
    int x;
};


int main()
{
    Cnt a; ++a;
    Cnt b = a++;
    cout << a.get() << endl;
    cout << b.get() << endl;
    return 0;
}
