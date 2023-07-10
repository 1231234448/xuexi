#include <iostream>

using namespace std;


int main()
{
    int a = 2089;
    while(true){
        cout << a % 10 << endl;
        a /= 10;
        if(a==0) break;
    }

    return 0;
}
