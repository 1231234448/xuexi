#include <iostream>
#include <set>

using namespace std;

struct STU{
    string name;
    int age;
    bool operator<(const STU& t) const {
        if(age==t.age) return name < t.name;
        return age < t.age;
    }
};
int main()
{
    set<STU> a;
    a.insert(STU{"zhang", 15});
    a.insert(STU{"li", 16});
    a.insert(STU{"tao", 10});
    a.insert(STU{"mao", 10});
    for(auto i=a.begin(); i!=a.end(); ++i)
        cout << (*i).name << ": " << (*i).age << endl;

    return 0;
}
