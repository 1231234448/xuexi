#include <iostream>
using namespace std;

class Punch{
public:
    Punch(){ data = 0; }
    void set(int day){
        if(day<1 || day>31) return;
        data |= 1 << (day-1);
    }
    bool get(int day){
        if(day<1 || day>31) return false;
        return  data & (1 << (day-1));
    }
    bool operator[](int day){ return get(day); }
private:
    unsigned int data; // 按二进制位记录每天打卡情况
};


int main()
{
    Punch a;
    a.set(5);
    cout << a[5] << endl;
    return 0;
}
