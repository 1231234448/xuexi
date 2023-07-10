#include <iostream>

using namespace std;

class Stack{
public:
    Stack() { n = 0; }
    void push(char x) { data[n++] = x; }
    char pop() {
        if(empty()) throw -1;
        return data[--n];
    }
    bool empty() { return n==0; }
private:
    char data[100];
    int n;
};

bool good(const char* s)
{
    Stack a;
    try{
        while(*s){
            if(*s=='(') a.push(')');
            if(*s=='[') a.push(']');
            if(*s=='{') a.push('}');
            if(*s==')' || *s==']' || *s=='}'){
                if(a.pop() != *s) return false;
            }
            s++;
        }
    }
    catch(int e){
        return false;
    }
    return a.empty();
}

int main()
{
    cout << good(".(.[..).]..") << endl;
    cout << good(".(...).]..") << endl;
    cout << good(".(.(..)...") << endl;
    cout << good(".(.[.].){.}..") << endl;
    return 0;
}
