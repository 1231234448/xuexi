#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char buf[] = "abcd";
    do{
        cout << buf << endl;
    }while(next_permutation(buf,buf+4));

    return 0;
}
