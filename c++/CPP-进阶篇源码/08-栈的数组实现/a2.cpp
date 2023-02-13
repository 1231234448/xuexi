#include <iostream>

using namespace std;

template <typename T>
struct IStack{
    virtual ~IStack() {}
    virtual IStack& push(const T&) = 0;
    virtual T pop() = 0;
    virtual bool empty() = 0;
};

template <typename T, int N>
class MyStack:public IStack<T>{
public:
    MyStack() { n = 0; }
    virtual MyStack& push(const T& x) override{
        if(n>=N) throw "stack overflow";
        data[n++] = x;
        return *this;
    }
    virtual T pop() override{
        if(n==0) throw "empty pop!";
        return data[--n];
    }
    virtual bool empty() override{
        return n == 0;
    }
private:
    T data[N];
    int n;
};

struct Point{
    int x;
    int y;
    friend ostream& operator<< (ostream& out, Point t){
        cout << "(" << t.x << "," << t.y << ") ";
    }
};


// 面向接口编程，不了解底层实现方式
template <typename T>
void clear(IStack<T>& s)
{
    while(!s.empty()){
        cout << s.pop() << endl;
    }
}

int main()
{
    MyStack<Point,200> a;
    a.push(Point{1,2}).push(Point{3,4}).push(Point{5,6});

    clear(a);

    return 0;
}
