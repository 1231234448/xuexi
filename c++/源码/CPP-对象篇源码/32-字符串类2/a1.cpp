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
    ~Str(){ clear(); }
    Str& operator=(const Str& t){ return *this = t.ps; }
    Str& operator=(const char* s) {
        clear();
        copy(s);
        return *this;
    }
    Str operator+(int x) const { return *this + Str(x); }
    Str operator+(const char* s) const {
        int n1 = ps? strlen(ps) : 0;
        int n2 = s? strlen(s) : 0;
        Str t;
        t.ps = new char [n1+n2+1];
        t.ps[0] = 0;
        if(ps) strcat(t.ps, ps);
        if(s) strcat(t.ps,s);
        return t;
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
        a = a + i;
    }

    cout << a << endl;


    return 0;
}
