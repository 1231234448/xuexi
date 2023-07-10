#include <iostream>

using namespace std;

class T{
public:
    T(){ A++; }
    ~T(){ A--; }
    int x;
    static int A;
};

int T::A = 0;  // 必须创建，否则类是蓝图，不会创建变量

int main()
{
    {
        T a;
        T* p = new T();
        delete p;
    }

    cout << T::A << endl;

    return 0;
}
