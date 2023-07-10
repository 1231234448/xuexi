#include <iostream>

using namespace std;

class Punch{
public:
    Punch(){ data = 0; }
    Punch& set(int day){
        if(day<1 || day>31) return *this;
        data |= 1 << (day-1);
        return *this;
    }
    bool get(int day){
        if(day<1 || day>31) return false;
        return  data & (1 << (day-1));
    }
    friend void debug_punch(Punch& x);
private:
    unsigned int data; // 按二进制位记录每天打卡情况
};

void debug_punch(Punch& x){
    cout << "puch.data:" << hex << x.data << endl;
}

int main()
{
    Punch a;
    a.set(5).set(10).set(12);
    cout << a.get(2) << endl;
    cout << a.get(5) << endl;

    debug_punch(a);

    return 0;
}
