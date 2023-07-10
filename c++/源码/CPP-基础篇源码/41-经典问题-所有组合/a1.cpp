#include <iostream>

using namespace std;

int main()
{
    for(int i=0; i<=1; i++)
        for(int j=0; j<=1; j++)
            for(int k=0; k<=1; k++){
                if(i) cout << "a";
                if(j) cout << "b";
                if(k) cout << "c";
                cout << endl;
            }

    return 0;
}
