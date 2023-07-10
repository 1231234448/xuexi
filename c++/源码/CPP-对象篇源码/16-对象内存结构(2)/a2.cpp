#include <iostream>
#include <string.h>
using namespace std;

class Stu{
public:
    Stu(){
        id = -1;
        name[0] = '\0';
        score = -9999;
    }
    Stu(int id, char* name){
        init(id, name, 0);
    }
    ~Stu(){
        cout << "destroy.. " << id << endl;
    }
    void init(int id, char* name, int score){
        this->id = id;
        strncpy(this->name, name, 25);
        this->score = score;
    }

    void inc(int x=1){ score += x; }
    void dec(int x) { score -= x; }
    void show(){
        cout << id << ": " << name << "," << score << endl;
    }
private:
    int id;
    char name[30];
    int score;
};


int main()
{
    Stu* a[5];  //指针数组
    for(int i=0; i<5; i++){
        a[i] = new Stu(101+i, "noname");
        a[i]->show();
    }

    for(int i=0; i<5; i++) delete a[i];

    return 0;
}

