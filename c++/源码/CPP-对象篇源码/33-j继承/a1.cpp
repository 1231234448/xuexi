#include <iostream>
using namespace std;

class Cnt{
public:
    Cnt(){n=0;}
    void inc(){n++;}
    int get(){return n;}
private:
    int n;
};


class Cnt2: public Cnt{
public:
    Cnt2(int m){ max = m; }
    Cnt2& inc(){
        if(get() >= max) return *this;
        Cnt::inc();
        return *this;
    }
private:
    int max;
};

class Cnt3{
public:
    Cnt3(int m){ max = m; }
    Cnt3& inc(){
        if(cnt.get() >= max) return *this;
        cnt.inc();
        return *this;
    }
    int get() { return cnt.get(); }
private:
    int max;
    Cnt cnt;
};


void f(Cnt& x)
{
    cout << x.get() << endl;
}

int main()
{
    Cnt2 a(3);
    a.inc().inc().inc().inc();
    f(a);
//    Cnt3 a(3);
//    a.inc().inc().inc().inc();
//    cout << a.get() << endl;
    return 0;
}
