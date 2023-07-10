#include <iostream>

using namespace std;


void show(int* a, const int W, const int H)
{
    for(int j=0; j<H; j++){
        for(int i=0; i<W; i++){
            cout << a[j*W+i] << " ";
        }
        cout << endl;
    }
}

void clear_border(int* a, const int W, const int H)
{
    for(int j=0; j<H; j++){
        for(int i=0; i<W; i++){
            if(i>0 && i<W-1 && j>0 && j<H-1) continue;
            a[j*W+i] = 0;
        }
    }
}

int main()
{
    int a[3][6];
    int *p = &a[0][0];  // == &(a[0][0])
    for(int i=0; i<sizeof(a)/sizeof(int); i++) p[i] = i+1;

    clear_border(&a[0][0],6,3);

    show((int*)a,6,3);

    return 0;
}
