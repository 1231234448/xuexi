#include <iostream>
using namespace std;

class MyArray{
public:
    MyArray(int size){
        pData = new int [size];
        this->size = size;
    }
    int& operator[] (int x){
        if(x<0 || x >=size) throw "bad index";
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
        MyArray a(10);
        a[10] = 555;
        cout << a[15] << endl;
    }
    catch(const char* e){
        cout << "ERR: " << e << endl;
    }
    catch(bad_array_new_length& e){
        cout << "ERR: " << e.what() << endl;
    }
    return 0;
}
