#include <iostream>

using namespace std;


struct IndexError: logic_error{
    IndexError(int min, int max, int x):logic_error(""){
        sprintf(err,"index must between %d-%d, but get: %d",
                min, max, x);
    }
    virtual const char* what() const throw() override{
        return err;
    }
    char err[100];
};

class MyArray{
public:
    MyArray(int size){
        pData = new int [size];
        this->size = size;
    }
    int& operator[] (int x){
        if(x<0 || x >=size) throw IndexError(0,size-1,x);
        return pData[x];
    }
    ~MyArray(){
        delete [] pData;
    }
private:
    int* pData;
    int size;
};

int main()
{
    try{
        MyArray a(20);
        a[9] = 555;
        cout << a[25] << endl;
    }
    catch(IndexError& e){
        cout << e.what() << endl;
    }
}
