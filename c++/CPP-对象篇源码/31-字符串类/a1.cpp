#include <iostream>
#include <string.h>
using namespace std;

class Str{
public:
    Str(){ ps = NULL; }
    Str(const char* s){ copy(s); }
    Str(const Str& t):Str(t.ps){}
    ~Str(){ clear(); }
    Str& operator=(const Str& t){ return *this = t.ps; }
    Str& operator=(const char* s) {
        clear();
        copy(s);
        return *this;
    }
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
    Str a("abc");    // 需要由 const char* 构造
    Str b = "xyz";   // 需要由 const char* 构造
    Str c = b;   // 需要由 Str 拷贝构造
    Str d = a + b + c + "1234";
    // Str + Str;  Str + char*;
    // char* + Str; Str = char*; Str = Str
    cout << d << endl;  // ostream << Str

    return 0;
}
