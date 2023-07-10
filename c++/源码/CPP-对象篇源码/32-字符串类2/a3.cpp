#include <iostream>
#include <string.h>
using namespace std;

class Str{
public:
    Str(int n){
        if(n<10) n=10;
        cap = n;
        ps = new char [cap];
        *ps = '\0';
    }
    Str():Str(10){}
    Str(const char* s):Str((s?strlen(s):0)+1){
        if(s) strcpy(ps, s);
    }
    Str(const Str& t):Str(t.ps){}

    ~Str(){
        delete [] ps;
        //cout << "~ ";
    }

    Str& operator=(const Str& t){ return *this = t.ps; }
    Str& operator=(const char* s) {
        int n = (s? strlen(s) : 0) + 1;
        if(cap < n){
            cap = n * 2;
            delete [] ps;
            ps = new char [cap];
        }
        if(s)
            strcpy(ps, s);
        else
            *ps = '\0';
        return *this;
    }
    Str operator+(int x) const { return *this + Str(x); }
    Str& operator+=(const char* s){
        if(s==NULL) return *this;
        char* p = ps;
        int n = strlen(ps) + strlen(s) + 1;
        if(cap < n){
            cap = n * 2;  // 多分配些
            ps = new char [cap];
            strcpy(ps, p);
            delete [] p;
        }
        strcat(ps, s);
        return *this;
    }
    Str operator+(const char* s) const {
        Str t(*this);
        t += s;
        return t;
    }
    // 为了隐式转换
    operator const char*() const { return ps; }  // Str -> const char*
    // 显示转换：从 Int 转为 Str
    static Str from(int x){
        Str t(30);
        itoa(x, t.ps, 10);
        return t;
    }
private:
    char* ps;  // 被包装主体
    int cap;
};

int main()
{
    Str a;
    for(int i=0; i<10; i++){
        a += Str::from(i);
    }

    cout << a << endl;

    return 0;
}
