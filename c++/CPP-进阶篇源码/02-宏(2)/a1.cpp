#include <iostream>
using namespace std;

#define V1 "27.3.6"
#define V2 "1.4"
#define VER(pre,v) pre "." #v
#define PR(x) cout << (x) << endl;

#define TO_STR(x) TO_S(x)
#define TO_S(x) #x

int main()
{
    PR(VER(V1,25))
    PR(VER(V2,25))

    PR(TO_STR(VER(V1,25)))

    return 0;
}
