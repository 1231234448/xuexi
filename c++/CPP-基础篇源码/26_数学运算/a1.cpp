#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

void shuffle(int* begin, int* end)
{
    int n = end - begin;
    srand(time(NULL));
    for(int i=0; i<100; i++){
        int a = rand() % n;
        int b = rand() % n;
        {int t=begin[a]; begin[a]=begin[b]; begin[b] = t;}
    }
}

void show(int* p, int* q)
{
    while(p<q) cout << *p++ << " ";
    cout << endl;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    shuffle(a,a+9);
    show(a,a+9);
    return 0;
}
