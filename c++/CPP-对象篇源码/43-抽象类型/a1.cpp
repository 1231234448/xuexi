#include <iostream>
using namespace std;

class SavAcc{
public:
    SavAcc() { balance = 0; }
    virtual int year_interest() final{
        int sum = balance;
        for(int i=0; i<12; i++){
            sum += (int)(sum * mon_inter_rate(i) / 100 + 0.5);
        }
        return sum - balance;
    }
    virtual double mon_inter_rate(int x) = 0;  // 强制子类必须完成
    void deposit(int x){  //存款
        balance += x;
    }
    int get_balance() { return balance; }
protected:
    int balance;    //余额
};
class T1SavAcc: public SavAcc{
public:
    virtual double mon_inter_rate(int x)  override {
        if(x<3) return 0.3;
        return 0.25;
    }
};
class T2SavAcc: public SavAcc{
public:
    virtual double mon_inter_rate(int x)  override {
        return 0.3;
    }
};
int main()
{
    T1SavAcc a;
    a.deposit(10000);
    cout << a.year_interest() << endl;
    cout << a.get_balance() << endl;
    return 0;
}
