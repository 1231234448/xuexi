#include <iostream>
using namespace std;


int main()
{
    int score = 85;
    char level = 'E';
    if(score >= 60) level = 'D';
    if(score >= 70) level = 'C';
    if(score >= 80) level = 'B';
    if(score >= 90) level = 'A';

    cout << level << endl;

    return 0;
}
