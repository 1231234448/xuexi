#include <iostream>

using namespace std;

// sp: 塔底左边距，h:塔高
void ta(int sp, int h)
{
    if(h<=0) return;
    ta(sp+1, h-1);
    for(int i=0; i<sp; i++) printf(" ");
    for(int i=0; i<h; i++) printf("%c", 'A'+i);
    for(int i=h-1-1; i>=0; i--) printf("%c", 'A'+i);
    printf("\n");
}

int main()
{
    ta(5,6);
    return 0;
}
