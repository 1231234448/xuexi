#include <iostream>
#include <boost/format.hpp>

using namespace std;

int main()
{
//    boost::format fmt("%2% - %3% - %1%");
//    fmt % 2008 % 8 % 31;
//    cout << fmt << endl;

//    boost::format fmt("|%1$10.2f|%1$-10.3f|%1$=10.2f");
//    fmt % 3.1415936;
//    cout << fmt << endl;
//    cout << boost::format("%b,%d,%04x")%true%254%254 << endl;

//    cout << boost::format("a%20tbcd") << endl;
//    cout << boost::format("aa%20tbbbb") << endl;
//    cout << boost::format("aaaa%20T*bbbbb") << endl;

    int a = 5, b = 6, c = 128;

    boost::format fmt("%s=%d, %010p");
    cout << fmt % "a" % a % &a << endl;
    cout << fmt % "b" % b % &b << endl;
    cout << fmt % "c" % c % &c << endl;

    return 0;
}
