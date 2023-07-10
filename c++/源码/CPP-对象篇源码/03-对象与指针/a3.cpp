#include <iostream>
#include <string.h>

using namespace std;

class MyA
{
public:
    void set(char* name, int age){
        x = age;
        p = new char [strlen(name)+1];
        strcpy(p, name);
    }
    void finish(){
        delete [] p;
    }
private:
    int x;
    char* p;
};

int main()
{
    MyA* p = new MyA();
    p->set("zhangsan", 10);
    //p->finish();
    p[0].finish();  // 数组其实就是指针的委婉写法

    delete p;  // 自己new的，别忘了啊

    return 0;
}
