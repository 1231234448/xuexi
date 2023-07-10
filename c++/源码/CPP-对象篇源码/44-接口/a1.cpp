#include <iostream>
using namespace std;

struct IFlyable{
    virtual void fly() = 0;
    virtual ~IFlyable(){}
};

struct IManmade{
    virtual double price() = 0;
    virtual ~IManmade() {}
};

class Bird: public IFlyable{
public:
    virtual void fly() override {
        cout << "I am a bird, flying..." << endl;
    }
};

class Plane: public IFlyable, public IManmade {
public:
    virtual void fly() override {
        cout << "a plane can fly..." << endl;
    }
    virtual double price() {
        return 112345.6;
    }
};

void f(IFlyable& x)
{
    cout << "beijing--->shanghai" << endl;
    x.fly();
}

void g(IManmade& x)
{
    if(x.price() < 1000)
        cout << "cheap!" << endl;
    else
        cout << "expensive!" << endl;

}

int main()
{
    Plane a;
    f(a);
    g(a);

    return 0;
}
