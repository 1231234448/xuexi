#include <iostream>
using namespace std;

class T{
public:
    class P{
    public:
        P(T* p):p(p){ p->n++; }
        P(P& t){ copy(t); }
        ~P(){ clear(); }
        void clear(){
            p->n--;
            if(p->n == 0) { delete p; p=NULL; }
        }
        void operator=(P& t){ clear(); copy(t); }
        T* operator->(){ return p; }
    private:
        void copy(P& t){ p = t.p; p->n++; }
        T* p;
    };

    T(){ cout << "T() .. " << endl; n=0; }
    ~T() { cout << "~T() .. " << endl; }
    void f() { cout << "T::f() .. " << endl; }
private:
    int n; // 本对象的引用计数
};

int main()
{
    T::P p(new T());  // 构造
    p->f();
    T::P q = p;  // 拷贝构造
    T::P s(new T());
    s = q;  // 对象赋值

    return 0;
}
