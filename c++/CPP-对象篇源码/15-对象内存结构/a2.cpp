#include <iostream>
#include <string.h>
using namespace std;

class Stu{
public:
    Stu(){
        id=-1;
        name = NULL;
        score=-999;
    }
    Stu(int id, char* name){
        init(id, name, 0);
    }
    ~Stu(){
        if(name){
            delete [] name;
            name = NULL;
        }
        cout << "destroy...stu.." << id << endl;
    }
    void init(int id, char* name, int score){
        this->id = id;
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
        this->score = score;
    }
    void inc(int x=1){ score += x; }
    void dec(int x) { score -= x; }
    void show(){
        cout << id << ": " << name << "," << score << endl;
    }
private:
    int id;
    char* name;
    int score;
};

int main()
{
//    Stu a(101, "zhangsan");
//    a.show();
    Stu a[10];
    char buf[100];
    for(int i=0; i<10; i++){
        sprintf(buf,"stu%d",i+1);
        a[i].init(100+i+1, buf, 20);
        a[i].show();
    }

    return 0;
}
