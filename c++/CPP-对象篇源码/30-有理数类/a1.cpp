#include <iostream>
using namespace std;

class Rati{
public:
    Rati(){ p=1; q=1; }
    Rati(int a, int b){ int g=gcd(a,b); p=a/g; q=b/g; }
    Rati(int a){ p=a; q=1; }
    Rati operator+(const Rati& t) const
    { return Rati(p*t.q+q*t.p, q*t.q); }
    Rati operator+(int t) const
    { return *this + Rati(t); }
    friend ostream& operator<<(ostream& os, const Rati& t);
    friend Rati operator+(int t1, const Rati& t2);
private:
    static int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int p;  // 分子
    int q;  // 分母
};

Rati operator+(int t1, const Rati& t2)
{
    return t2 + t1;
}
ostream& operator<<(ostream& os, const Rati& t)
{
    cout << t.p;
    if(t.q != 1) cout << "/" << t.q;
    return os;
}
int main()
{
    Rati a(30,50);
    cout << a << endl;
    cout << Rati(2) << endl;
    cout << Rati(1,3) + Rati(1,6) << endl;
    return 0;
}
