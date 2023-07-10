#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<int, string> a;
    a.insert(pair<int,string>(1, "zhang"));
    auto it = a.insert(pair<int,string>(2,"wang")); // 返回迭代器，指向新元素
    a.insert(pair<int,string>(2,"li"));
    a.insert(it, pair<int,string>(2,"zhao")); // 尽量在 it 之前插入
    a.insert({{4,"zhou"},{4,"wu"},{4,"zheng"}});  // c++11 标准

    auto pa = a.equal_range(2);

    for(auto i=pa.first; i!=pa.second; ++i)
        cout << i->first << ":" << i->second << endl;
    return 0;
}
