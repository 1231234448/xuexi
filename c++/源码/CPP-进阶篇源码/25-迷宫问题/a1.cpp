#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<char>> read()
{
    ifstream in("d:\\1.txt");
    int M, N;
    in >> M >> N;
    vector<vector<char>> t(M+2, vector<char>(N+2,'1'));
    in.ignore();
    string s;
    for(int i=1; i<=M; i++){
        getline(in, s);
        copy(s.cbegin(), s.cend(), t[i].begin()+1);
    }

    return t;
}
int main()
{
    auto da = read();

    for(int i=0; i<da.size(); i++){
        for(int j=0; j<da[i].size(); j++) cout << da[i][j];
        cout << endl;
    }

    return 0;
}
