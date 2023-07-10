#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>

using namespace std;


vector<vector<char>> read(const char* fname)
{
    ifstream in(fname);
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

int solve(vector<vector<char>>& da)
{
    struct Point{
        int row; int col;
        array<Point, 4> go(){
            array<Point, 4> t;
            t[0] = Point{row-1, col};
            t[1] = Point{row+1, col};
            t[2] = Point{row, col-1};
            t[3] = Point{row, col+1};
            return t;
        }
    };

    queue<Point> w;
    w.push(Point{1,1});
    int k = 0;

    while(w.size()>0){
        int n = w.size();
        for(int i=0; i<n; i++){
            auto t = w.front();
            if(t.row == da.size()-2 && t.col == da[0].size()-2)
                return k;
            auto tt = t.go();
            for(auto j=tt.cbegin(); j!=tt.cend(); ++j){
                if(da[(*j).row][(*j).col]=='.'){
                    da[(*j).row][(*j).col] = '*';
                    w.push(*j);
                }
            }
            w.pop();
        }
        k++;
    }

    return -1;
}

int main()
{
    auto da = read("d:\\2.txt");
    cout << solve(da) << endl;

    return 0;
}
