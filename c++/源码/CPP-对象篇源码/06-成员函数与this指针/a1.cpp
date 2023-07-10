#include <iostream>

using namespace std;

class Timer{
public:
    void set(int x);
    int get();
    Timer& tick();
private:
    int sec;
};

void Timer::set(int x)
{
    sec = x;
}

int Timer::get()
{
    //cout << this << endl;
    return sec;
}

Timer& Timer::tick()
{
    if(sec>0) sec--;
    return *this;
}
////------------------------------
struct T{
    int sec;
};
void set(T* that, int x)
{
    that->sec = x;
}
int get(T* that)
{
    return that->sec;
}
///// -------------------------------

int main()
{
//    T a;
//    set(&a, 10);
//    cout << get(&a) << endl;

    Timer a;
    a.set(10);
    cout << &a << endl;

    a.tick().tick().tick();

    cout << a.get() << endl;


    return 0;
}
