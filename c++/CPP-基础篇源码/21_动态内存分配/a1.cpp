#include <iostream>
using namespace std;


int main()
{
    {
    int a[3] = {10,20,30};
    int* b = (int*)malloc(sizeof(int) * 3);

    for(int i=0; i<3; i++) b[i] = a[i];
    cout << b[2] << endl;

    free(b);
    }

    {
    int a[3] = {10,20,30};
    //int* b = (int*)malloc(sizeof(int) * 3);
    int* b = new int [3];

    for(int i=0; i<3; i++) b[i] = a[i];
    cout << b[2] << endl;

    //free(b);
    delete [] b;
    }

    return 0;
}
