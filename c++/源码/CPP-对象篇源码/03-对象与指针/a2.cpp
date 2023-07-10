#include <iostream>
#include <string.h>

using namespace std;

class MyA
{
public:
    void set(char* name, int age){
        x = age;
        p = new char [strlen(name)+1];
        strcpy(p,name);
    }
private:
    int x;
    char* p;
};

int main()
{
    MyA a;
    a.set("zhangsan", 10);

    cout << sizeof(MyA) << endl;

    return 0;
}
