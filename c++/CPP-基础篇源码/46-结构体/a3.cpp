#include <iostream>
#include <string.h>
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
//    STU2 t1 = {name, 15};
//    STU2 t2 = t1;
    STU1 t1;
    strcpy(t1.name, name);
    t1.age = 15;
    STU1 t2 = t1;
    cout << sizeof(t1) << endl;
    t1.name[0] = 'X';
    cout << t2.name << endl;

    return 0;
}
