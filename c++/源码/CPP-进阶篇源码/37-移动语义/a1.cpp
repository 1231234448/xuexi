#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct A{
    A() {cout << ".. default construct" << endl; }
    A(const A&) { cout << ".. copy construct" << endl; }
    A(A&& t) { cout << ".. move construct" << endl;  t.p=0;}
    ~A() { cout << ".. destroy" << endl; }
    void operator=(const A&) { cout << " copy " << endl; }
    void operator=(const A&&) { cout << " move " << endl; }
    void f() { cout << "A::f()" << endl; }
    char* p;
};

void f(const A&& x){
    A t(x);
}
int main()
{
    vector<A> v;
    for(int i=0; i<1; i++){
        //A t;
        v.push_back(A());
    }

    return 0;
}
