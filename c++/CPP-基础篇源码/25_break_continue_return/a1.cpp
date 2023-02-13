#include <iostream>
using namespace std;

int main()
{
    for(int n=2; n<100; n++){
        bool is_prime = true;
        for(int i=2; i<n; i++){
            if(n % i == 0){
                is_prime = false;
                break;
            }
        }
        if(!is_prime) continue;
        cout << n << " ";
        //if(is_prime) cout << n << " ";
    }
    cout << endl;

    return 0;
}
