#include <iostream>

using namespace std;

class Cnt{
public:
    Cnt(){
        x = 0;
    }
    Cnt& inc(){ x++; return *this; }
    Cnt& dec(){ x--; return *this; }
    void show() { cout << x << endl; }
    void add(Cnt& t){
        x += t.x;
    }
    static Cnt add(Cnt& a, Cnt& b){
        Cnt t;
        t.x = a.x + b.x;
        return t;
    }
    static Cnt add(int a, Cnt& b){
        Cnt a1;
        a1.x = a;
        return add(a1, b);
    }
    static void help(){
        cout << "_____ Cnt help ____" << endl;
        cout << " Cnt a_name; " << endl;
        cout << " a_name.inc(); // add one " << endl;
        cout << " ....... " << endl;
    }
    static Cnt* create(const char* txt){
        Cnt* p = new Cnt();
        sscanf(txt,"init=%d",&p->x);
        return p;
    }
private:
    int x;
};


int main()
{
    Cnt* p = Cnt::create("init=50");
    p->show();
    delete p;

//    Cnt a;
//    a.inc().inc();
//    Cnt b;
//    b.inc();
//    a.add(b);
//    a.show();
//    Cnt c = Cnt::add(a,b);
//    c.show();

//    Cnt::add(100,b).show();
//    Cnt::help();

    return 0;
}
