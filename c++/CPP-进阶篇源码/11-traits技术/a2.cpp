#include <iostream>

using namespace std;

template <typename T>
struct TestHelper{
    static const bool isPointer = false;
};

template <typename T>
struct TestHelper<T*>{
    static const bool isPointer = true;
};

template <typename T>
class Test{
public:
    void f() {
        if(TestHelper<T>::isPointer) cout<< "POINTER ";
        cout << "do somthing..." << endl;

    }
};

int main()
{
    Test<int>().f();
    Test<int*>().f();
    return 0;
}
