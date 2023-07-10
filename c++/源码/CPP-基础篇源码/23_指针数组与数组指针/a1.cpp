#include <iostream>

using namespace std;

int** get_table()
{
    int **p = new int* [9+1];
    for(int j=0; j<9; j++){
        p[j] = new int[j+1+1];
        p[j][0] = j+1;
        for(int i=1; i<j+1+1; i++) p[j][i] = i*(j+1);
    }
	p[9] = NULL;
    return p;
}

int main()
{
    int** p = get_table();

    cout << (p[4])[0] << endl;

    for(int** q=p; *q; q++) delete [] *q;
    delete [] p;

    return 0;
}
