#include <iostream>
using namespace std;


int main()
{
    int score = 85;
    char level = 'E';
    switch (score / 10) {
    case 9:
    case 10:
       level = 'A';
        break;
    case 8:
        level = 'B';
        break;
    case 7:
        level = 'C';
        break;
    case 6:
        level = 'D';
    }
    cout << level << endl;

    return 0;
}
