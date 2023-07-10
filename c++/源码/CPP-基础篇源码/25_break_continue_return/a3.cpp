#include <iostream>
using namespace std;

int main()
{
    for(int n=2; n<100; n++){
        for(int i=2; i<n; i++) if(n % i == 0) goto noprint;
        cout << n << " ";
        noprint: ;
    }
    return 0;
}
