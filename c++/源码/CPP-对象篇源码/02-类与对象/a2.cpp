#include <iostream>
using namespace std;

// 定时器
class Timer
{
public:
    void set(int min, int sec);
    void tick();
    int  get_min();
    int  get_sec();
private:
    int sec;
};


void Timer::set(int m, int s)
{
    sec = m * 60 + s;
}

void Timer::tick()
{
    if(sec>0) sec--;
    if(sec==0)
        cout << "beep ... beep ... " << endl;
}

int Timer::get_min() { return sec/60; }
int Timer::get_sec() { return sec%60; }

int main()
{
    Timer a;
    a.set(1,15);
    a.tick();
    cout << a.get_min() << "," << a.get_sec() << endl;
    for(int i=0; i<80; i++) a.tick();


    return 0;
}
