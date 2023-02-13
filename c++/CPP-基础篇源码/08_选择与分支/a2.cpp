#include <iostream>
using namespace std;


int main()
{
    int x = 2000;
//    bool leap = x % 4 == 0 && x % 100 != 0 || x % 400 == 0;
    bool leap = false;
    if(x%4==0) leap = true;
    if(x%100==0) leap = false;
    if(x%400==0) leap = true;
    cout << leap << endl;
    return 0;
}
