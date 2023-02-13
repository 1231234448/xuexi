#include <iostream>


using namespace std;

int main()
{
    int a;
    while(1){
        cin >> a;
        if(cin.good()) break;
        cout << "err data, input again!" << endl;
        cin.clear();  // 清空状态标志
        while(cin.get()!='\n');  // 清空缓冲区
    }
    cout << "a: " << a << endl;

    return 0;
}

