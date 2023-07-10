#include <iostream>

using namespace std;

class Cnt{
public:
    Cnt(){ x = 0; }
    ~Cnt() { cout << "destroy .. counter ... " << x << endl; }
    Cnt& inc() { x++; return *this; }
    void dec() { x--; }
    int get() { return x; }
private:
    int x;
};


Cnt* make_cnt()
{
    return new Cnt();
}

bool free_cnt(Cnt* p)
{
    delete p;
}

int main()
{
    Cnt* p = make_cnt();
    p->inc().inc().inc();
    free_cnt(p);

    return 0;
}
