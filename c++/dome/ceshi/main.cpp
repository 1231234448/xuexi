#include <iostream>
using namespace std;

int main() {
    int a = 10;     // ����һ����������a
    int* ptr = &a;  // ����һ��ָ��������ָ��ptr������a�ĵ�ַ��ֵ��ptr

    cout << a << endl;    // ���a��ֵ��������Ϊ10
    cout << *ptr << endl; // ���ͨ��ָ����ʵ�ֵ��������ҲΪ10

    return 0;
}
