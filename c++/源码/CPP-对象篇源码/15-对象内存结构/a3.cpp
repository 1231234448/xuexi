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
    Stu* a[5];  //指针数组
    for(int i=0; i<5; i++){
        a[i] = new Stu(101+i, "noname");
        a[i]->show();
    }
    //
    for(int i=0; i<5; i++) delete a[i];
    return 0;
}
