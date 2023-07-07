#include <iostream>

using namespace std;


int main()
{
    int n = 24;
    for(int i=2; i<n; i++){
        if(n % i == 0){
            cout << i << " ";
            n = n / i;
            i--;
        }
    }
    if(n > 1) cout << n;
    cout << endl;

    return 0;
}
