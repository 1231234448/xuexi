#include <iostream>
using namespace std;

class IMyTag{
public:
    virtual ~IMyTag() =0 ;
};
IMyTag::~IMyTag(){}
class A:public IMyTag{
public:
    //virtual ~A(){}
};

int main()
{
    IMyTag* p = new A();
    delete p;

    return 0;
}
