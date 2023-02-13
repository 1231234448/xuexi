#include <iostream>

using namespace std;

class Cnt{
public:
    Cnt(){ x = 0; }
    ~Cnt() { cout << "destroy .. counter ... " << x << endl; }
    void inc() { x++; }
    void dec() { x--; }
    int get() { return x; }
private:
    int x;
};

void f(Cnt x)
{
    for(;x.get(); x.dec()){
        cout << "f..work..." << endl;
    }
}

int main()
{
    Cnt a;
    a.inc();
    a.inc();
    f(a);
    cout << a.get() << endl;
    return 0;
}
