#include <iostream>
using namespace std;

class T{
public:
    class P{
    public:
        P(T* p):p(p){}
        ~P(){ if(p){delete p; p=NULL;} }
        T* operator->(){ return p; }
    private:
        T* p;
    };
    T(){ cout << "T() .. " << endl; }
    ~T() { cout << "~T() .. " << endl; }
    void f() { cout << "T::f() .. " << endl; }
};

struct Node{
    Node(T* t):data(t){next=NULL;}
    T::P data;
    Node* next;
};

int main()
{
    Node a(new T());
    Node b(new T());
    a.next = &b;
//    T::P p = new T();
//    p->f();
    return 0;
}
