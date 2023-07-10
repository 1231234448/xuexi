#include <iostream>

using namespace std;

void f()
{
    cout << "there is no space any more" << endl;
}

int* bad()
{
    return new int[1000 * 1000];
}

int main()
{
    set_new_handler(f);

    for(int i=0; i<490; i++){
        cout << i << " ";
        bad();
    }

    return 0;
}
