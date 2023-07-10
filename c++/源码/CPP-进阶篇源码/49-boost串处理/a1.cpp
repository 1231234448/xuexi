#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    using namespace boost::algorithm;

//    string s = "abcdAB";
//    cout << to_upper_copy(s) << endl;
//    to_lower(s);
//    cout << s << endl;

//    string s = "abc,123;xyz,1111,123,ttt";
//    cout << erase_first_copy(s,"123") << endl;
//    cout << erase_nth_copy(s,",",2) << endl;
//    cout << erase_last_copy(s,",") << endl;
//    cout << erase_all_copy(s,",") << endl;
//    cout << erase_head_copy(s,3) << endl;
//    cout << erase_tail_copy(s,3) << endl;

//    string a[] = {"zhang", "wang", "li", "zhao"};
//    cout << join(a, ",") << endl;

//    string s = "   abc   ";
//    cout << "|" << trim_left_copy(s) << "|" << endl;
//    cout << "|" << trim_right_copy(s) << "|" << endl;
//    cout << "|" << trim_copy(s) << "|" << endl;
//    string s = "abc ,,; .";
//    cout << "|" << trim_copy_if(s, is_any_of(",; .")) << "|" << endl;

//    string s = "abc1234xyz";
//    cout << starts_with(s, "abc") << endl;
//    cout << ends_with(s, "xyz") << endl;
//    cout << contains(s, "123") << endl;

    string s = "123,abc,xyz,,qqq";
    vector<string> v;
    split(v, s, [](char x){return x==',';});
    for(auto i: v) cout << i << " ";
    
    
    return 0;
}
