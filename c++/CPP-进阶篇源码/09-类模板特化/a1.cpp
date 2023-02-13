#include <iostream>

using namespace std;

template <typename T1, typename T2>
class MyA{
public:
    MyA(const T1& a, const T2& b){
        cout << "MyA(T1, T2)" << endl;
    }
    void f1() { cout << "f1" << endl; }
    void f2() { cout << "f2" << endl; }
};

// MyA 模板的特化版，如需要，必须重新定义所有函数，或添加新函数
template<>
class MyA<int, int>{
public:
    MyA(const int& a, const int& b){
        cout << "MyA(int, int)" << endl;
    }
};

// 可以重用 MyA 模板的内容
struct MyB: public MyA<double,double>{
    MyB(int x, int y):MyA(x,y){}
};

int main()
{
    MyA<int, double> a(1,1.3);
    MyA<int, int> b(1,1);
    MyB c(2.0,2.0);
    c.f1();

    return 0;
}
