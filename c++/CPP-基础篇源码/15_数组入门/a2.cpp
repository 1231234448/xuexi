#include <iostream>

using namespace std;

int main()
{
    int a[9] = {9,7,2,5,3,6,1,4,8};
    int m = a[0];
    for(int i=1; i<9; i++){
        if(a[i]>m) m = a[i];
    }
    cout << m << endl;

    return 0;
}
