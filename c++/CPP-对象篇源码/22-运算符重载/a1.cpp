#include <iostream>
using namespace std;

class Cnt{
public:
    Cnt(){ x=0; }
    Cnt& inc() { x++; return *this; }
    Cnt& dec() { x--; return *this; }
    int get() { return x; }

    Cnt operator+(Cnt& t){ return Cnt(x+t.x); }
    Cnt operator+(int t){return Cnt(x+t); }
private:
    Cnt(int a){ x = a; }
    int x;
    friend Cnt operator+(int, Cnt&);
    friend ostream& operator<<(ostream& os, Cnt&);
};

Cnt operator+(int a, Cnt& b) { return Cnt(a + b.x); }
ostream& operator<<(ostream& os, Cnt& t) { os << t.x; return os; }

int main()
{
    Cnt a; a.inc(); a.inc();
    Cnt b; b.inc();
    Cnt c = 100 + a + b + 10;
    cout << c.get() << endl;

    cout << c << endl;

    return 0;
}
