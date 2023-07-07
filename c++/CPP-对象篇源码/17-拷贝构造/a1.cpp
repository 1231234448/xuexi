#include <iostream>

using namespace std;


class A{
public:
    A(){  cout << "default create" << endl; }
    A(A& x){ cout << "copy create" << endl; }
    ~A(){ cout << "destroy " << endl; }
};

A f(A x){ return x; }

int main()
{
//    A a;
//    A b = a;
//    A c(a);

    A a;
    f(a);

    return 0;
}
