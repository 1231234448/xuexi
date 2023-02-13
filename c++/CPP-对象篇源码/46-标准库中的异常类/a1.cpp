#include <iostream>

using namespace std;

long long fac(int x)
{
    if(x<0) throw invalid_argument("factorial: x<0");
    if(x==0) return 1LL;
    return fac(x-1) * x;
}
int main()
{

    fac(-10);
//    try{
//        int* a = new int[-10];
//    }
//    catch(bad_array_new_length& e){
//        cout << e.what() << endl;
//    }

    return 0;
}

