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
class B;
class A{
public:
    friend void fa(A& t);
    friend void fb(B& t);
private:
    int a;
};
class B: public A{
public:
    friend void fb(B& t);
private:
    int b;
};

void fa(A& t){ t.a++; }
void fb(B& t){ t.b++; t.a++; }

int main()
{

    return 0;
}
