#include <iostream>

using namespace std;

template <typename T>
struct Point{
    Point(T a, T b):x(a),y(b){}
    friend ostream& operator<< (ostream& out, Point<T>& obj){
            out << "(" << obj.x << "," << obj.y << ") ";
            return out;
    }
    T x;
    T y;
};

//template <typename T>
//ostream& operator<< (ostream& out, Point<T>& obj){
//    out << "(" << obj.x << "," << obj.y << ") ";
//    return out;
//}

int main()
{
    Point<int> a(1,2);
    Point<double> b(2.3, 4);
    cout << a << endl;
    cout << b << endl;
    return 0;
}
