#include <iostream>
using namespace std;


int main()
{
    // 0.3 用二进制不能精确表示
    int a = 68280;
    int r = a * 0.3;  // 舍弃小数
    cout << r << endl;
    cout << (a * 0.3) << endl; // 四舍五入
    return 0;
}
