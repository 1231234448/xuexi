#include <iostream>
#include <cmath>

using namespace std;

///////// .h
template <typename T> class Point;

template <typename T>
ostream& operator<< (ostream& out, Point<T>& obj);

template <typename T>
struct Point{
    Point(T a, T b):x(a),y(b){}
    friend ostream& operator<< <T> (ostream& out, Point<T>& obj);
    double distance(Point<T>& that);
    T x;
    T y;
};

////////// .cpp
template <typename T>
ostream& operator<< (ostream& out, Point<T>& obj){
    out << "(" << obj.x << "," << obj.y << ") ";
    return out;
}

template <typename T>
inline SQ(T x) { return x * x; }

template <typename T>
double Point<T>::distance(Point<T>& t)
{
    return sqrt(SQ(t.x-x) + SQ(t.x-x));
}

int main()
{
    Point<int> a(1,2);
    Point<int> b(3,4);
    Point<double> c(2.3, 4);
    cout << a << b << c<< endl;
    cout << a.distance(b) << endl;
    return 0;
}
