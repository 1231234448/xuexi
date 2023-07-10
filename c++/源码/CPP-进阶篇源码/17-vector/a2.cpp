#include <iostream>
#include <vector>


using namespace std;

int main()
{
    vector<int> a;
    for(int i=0; i<10; i++) a.push_back(i*10);

    a.erase(a.begin());
    a.erase(a.begin()+3,a.begin()+5);

    for(int i=0; i<a.size(); i++) cout << a[i] << " ";
    cout << endl;


    return 0;
}
