#include <iostream>

using namespace std;

void fill(char* a)
{
    for(int i=0; i<3*4; i++) a[i] = 'A' + i;
}

void show(char(*a)[4])
{
    for(int j=0; j<3; j++){
        for(int i=0; i<4; i++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}


int main()
{
    char a[3][4];
    fill((char*)a);

    show(a);

    return 0;
}
