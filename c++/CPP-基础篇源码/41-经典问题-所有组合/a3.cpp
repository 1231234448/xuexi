#include <iostream>
#include <string.h>
using namespace std;

// s: 待取串, n: 还要取几个, pick: 选哪些，k:考虑第k个物品
void zuhe(char* s, int n, int* pick, int k)
{
    if(n==0){
        for(int i=0; i<k; i++) if(pick[i]) cout << s[i];
        cout << endl;
        return;
    }
    if(k==strlen(s)) return;

    pick[k] = 0;
    zuhe(s, n, pick, k+1);
    pick[k] = 1;
    zuhe(s, n-1, pick, k+1);
}

void zuhe(char* s, int n)
{
    int pick[100];
    zuhe(s, n, pick, 0);
}

int main()
{
    zuhe("ABCD", 2);

    return 0;
}
