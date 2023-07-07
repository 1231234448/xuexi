#include <iostream>
using namespace std;

typedef enum {Mon, Tue, Wed, Thu, Fri, Sat, Sun} WEEK;

int main()
{
    WEEK a = Wed;
    WEEK b = Fri;
    cout << a << b << endl;
    cout << (a+2==b) << endl;

    return 0;
}
