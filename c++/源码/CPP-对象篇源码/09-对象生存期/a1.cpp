#include <iostream>

using namespace std;


class T{
public:
    int x;
    T(int x){ this->x = x; }
    ~T(){
        cout <<  x << " destroy..T" << endl;
    }
};


int main()
{
    T a(1);
    {
        T b(2);
    }
    for(T c(3);0;){}
    for(int i=0; i<3; i++){
        T d(4);
    }
    return 0;
}
