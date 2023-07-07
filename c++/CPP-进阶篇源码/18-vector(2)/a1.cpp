#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


struct Point{
    int x;
    int y;
    bool operator< (const Point& t) const { return x < t.x; }
    friend ostream& operator<< (ostream& os, const Point& t) {
        os << "(" << t.x << "," << t.y << ")";
        return os;
    }
};


int main()
{
    vector<Point> a;
    a.push_back(Point{2,5});
    a.push_back(Point{3,1});
    a.push_back(Point{1,8});
    sort(a.begin(), a.end());
    copy(a.begin(), a.end(), ostream_iterator<Point>(cout, " "));
    cout << endl;
    return 0;
}
