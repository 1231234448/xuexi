#include <iostream>

using namespace std;

int main()
{
    for(int n = 2; n<=100; n++){
        bool tag = true;
        for(int i=2; i<n; i++){
            if(n % i ==0){
                tag = false;
                break;
            }
        }
        if(tag) cout << n << " ";
    }
    cout << endl;

    return 0;
}
