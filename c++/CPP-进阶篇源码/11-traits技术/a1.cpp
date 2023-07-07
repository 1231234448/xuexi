#include <iostream>

using namespace std;


template <typename T, bool isPointer>
class Test{
public:
    void f() {
        if(isPointer) cout<< "POINTER ";
        cout << "do somthing..." << endl;

    }
};

int main()
{
    Test<int,false>().f();
    Test<int*, true>().f();
    return 0;
}
