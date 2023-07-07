#include <iostream>

using namespace std;


struct STU1
{
    char name[20];
    int age;
};

struct STU2
{
    char* name;
    int age;
};

int main()
{
    char name[] = "zhangsan";
    STU2 t1 = {name, 15};
    STU2 t2 = t1;
    cout << sizeof(t1) << endl;
    t1.name[0] = 'X';
    cout << t2.name << endl;

    return 0;
}
