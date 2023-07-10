#include <iostream>

using namespace std;

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
void fb(B& t){ t.b++; t.a++; } // 不可以，必须在A类中授权

int main()
{

    return 0;
}
