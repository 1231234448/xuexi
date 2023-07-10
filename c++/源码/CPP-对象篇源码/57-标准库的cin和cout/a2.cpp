#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

int main()
{
    ifstream in("d:\\1.txt");
    if(!in) {
        cout << "no such file!" << endl;
        return -1;
    };

    char buf[100];
    while(in.getline(buf, 80)){
        cout << buf << endl;
    }

    return 0;
}

