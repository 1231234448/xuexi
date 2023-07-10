#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

struct STU{
    string name;
    int age;
    bool operator> (const STU& t) const {
        return name > t.name;
    }
};

int main()
{
    vector<STU> a = {
        STU{"zhang", 20},
        STU{"wang", 30},
        STU{"li", 25},
        STU{"wang", 20},
        STU{"zhao", 22},
        STU{"wang", 50},
        STU{"wang", 12},
        STU{"li", 15}
    };

    sort(a.begin(), a.end(), greater<STU>());
    for(int i=0; i<a.size(); i++){
        cout << a[i].name << ", " << a[i].age << endl;
    }
    return 0;
}
