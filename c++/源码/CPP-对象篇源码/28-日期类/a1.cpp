#include <iostream>

using namespace std;

class Date{
public:
    Date(){ k=0; }
    Date(int y, int m, int d){ k = ymd_to_k(y,m,d); }
    int year() { int y, m, d; k_to_ymd(k, y, m, d); return y; }
    int month() { int y, m, d; k_to_ymd(k, y, m, d); return m; }
    int day() { int y, m, d; k_to_ymd(k, y, m, d); return d; }
    int week_day() { return k % 7; }
    int operator-(Date& t){ return k - t.k; }
    Date operator+(int x){ Date t; t.k = k + x; return t; }
    Date operator-(int x){ return *this + (-x); }
    friend ostream& operator<<(ostream& os, Date& t);
private:
    static bool leap_year(int y){
        return (y%4==0 && y%100!=0) || y%400==0;
    }
    static int ymd_to_k(int y, int m, int d);
    static void k_to_ymd(int k, int& y, int& m, int& d);
    int k;  //记录距离 公元1年1月1日，过去了多少天。
};
//输出
ostream& operator<<(ostream& os, Date& t)
{
    printf("%04d-%02d-%02d", t.year(), t.month(), t.day());
    return os;
}
// 年月日 转为： 距离公元元年经过天数
int Date::ymd_to_k(int y, int m, int d)
{
    int M[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(Date::leap_year(y)) M[2]++;
    int k = 0;
    for(int i=1; i<y; i++) k += 365 + leap_year(i);
    for(int i=1; i<m; i++) k += M[i];
    return k + d;
}
// 距离公元元年经过天数 转为： 年月日
void Date::k_to_ymd(int k, int& y, int& m, int& d)
{
    int M[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=1;; i++){
        int t = 365 + Date::leap_year(i);
        if(k<=t){
            y = i;
            break;
        }
        k -= t;
    }
    if(Date::leap_year(y)) M[2]++;
    for(int i=1;;i++){
        if(k<=M[i]){
            m = i;
            break;
        }
        k -= M[i];
    }
    d = k;
}

int main()
{
    Date a(2000,12,31);
    cout << a << endl;
    Date b(2001,1,1);
    cout << b << endl;
    cout << (b-a) << endl;
    cout << Date(2022,1,15).week_day() << endl;
   Date c = a + 30;
    cout << c << endl;
    return 0;
}
