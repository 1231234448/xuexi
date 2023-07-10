#include <iostream>

using namespace std;

struct A{
    A() { cout << "acquire resource..." << endl; }
    ~A() { cout << "free resource...." << endl; }
};
void f()
{
    cout << "begin..." << endl;
    A a;
    throw "bad argument";
    cout << "after exception.." << endl;
}
int main()
{
    try{
        f();
    }
    catch(...){

    }

    return 0;
}
