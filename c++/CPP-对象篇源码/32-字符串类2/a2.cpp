#include <iostream>
#include <string.h>
using namespace std;

class Str{
public:
    Str(){ ps = NULL; }
    Str(const char* s){ copy(s); }
    Str(const Str& t):Str(t.ps){}
    Str(int x){
        ps = new char[30];
        itoa(x, ps, 10);
    }
    ~Str(){ clear(); cout << "~ ";}
    Str& operator=(const Str& t){ return *this = t.ps; }
    Str& operator=(const char* s) {
        clear();
        copy(s);
        return *this;
    }
    Str operator+(int x) const { return *this + Str(x); }
    Str& operator+=(const char* s){
        if(s==NULL) return *this;
        char* p = ps;
        ps = new char [len()+strlen(s)+1];
        ps[0] = 0;
        if(p) strcat(ps, p);
        strcat(ps, s);
        if(p) delete [] p;
        return *this;
    }
    Str operator+(const char* s) const {
        Str t(*this);
        t += s;
        return t;
    }
    int len(){
        if(ps==NULL) return 0;
        return strlen(ps);
    }
    void reverse(){ if(ps) strrev(ps); }
    operator const char*() const { return ps; }  // Str -> const char*
private:
    void clear(){
        if(ps){
            delete [] ps;
            ps=NULL;
        }
    }
    void copy(const char* s){
        if(s==NULL) {
            ps = NULL;
            return;
        }
        ps = new char[strlen(s)+1];
        strcpy(ps, s);
    }
    char* ps;  // 被包装
};

int main()
{
    Str a;
    for(int i=0; i<10; i++){
        a += Str(i);
    }

    cout << a << endl;


    return 0;
}
