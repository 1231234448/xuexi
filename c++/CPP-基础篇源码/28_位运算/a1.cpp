#include <iostream>

using namespace std;

// 把第n位设置为x
void set_nth(unsigned char* data, int n, bool x)
{
    int a = n / 8, b = n % 8;
    if(x)
        data[a] |= 0x80 >> b;  //目标位为1，其它为0
    else
        data[a] &= ~(0x80 >> b);  //目标位为0，其它位为1
}
// 取得第n位的值（0或1）
bool get_nth(unsigned char* data, int n)
{
    int a = n / 8, b = n % 8;
    return data[a] & (0x80 >> b);
}
// 主调方需要准备bool数组的存储空间
int main()
{
    unsigned char data[20];
    set_nth(data, 100, true);
    cout << get_nth(data, 100) << endl;
    return 0;
}
