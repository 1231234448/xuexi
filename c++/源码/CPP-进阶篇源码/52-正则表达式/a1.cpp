#include <iostream>
#include <regex>

using namespace std;

int main()
{
//    regex re(R"(\d+)");
//    cout << regex_match("12345", re) << endl;
//    cout << regex_match("12ab345", re) << endl;
//    cout << regex_match("abcAZ", regex("[a-zA-Z]+")) << endl;

//    regex re(R"(\d{6}(19|20)\d{2}[01]\d[0-3]\d\d{3}[0-9xX])");
//    cout << regex_match("25122219600230332x", re) << endl;
//    cout << regex_match("25122219602130332x", re) << endl;
//    cout << regex_match("251222196002453320", re) << endl;

    regex re(R"(([[:alnum:]_\.\-])+\@([[:alnum:]_\.\-])+\.[a-zA-Z]{2,4})");
    cout << regex_match("guo-ti@163ab.com", re) << endl;
    cout << regex_match("gyh@163abc", re) << endl;
    cout << regex_match("xx.yy.zhang16@111.com", re) << endl;
    return 0;
}
