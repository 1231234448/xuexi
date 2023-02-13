#include <iostream>

using namespace std;

// 输出乘法表的某一项
// row: 行号，i: 列号
void t99_item(int row, int i)
{
    cout << i << "x" << row << "=" << row * i;
}

// 输出乘法表的一行
// row: 行号
void t99_row(int row)
{
    for(int i=1; i<=row; i++){
        t99_item(row,i);
        cout << " ";
    }
}

int main()
{
    for(int i=1; i<=9; i++){
        t99_row(i);
        cout << endl;
    }

    return 0;
}
