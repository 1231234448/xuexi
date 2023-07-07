#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    stack<int> w;

    stringstream ss("10 20 + 1 2 + *");
    string s;
    while(ss >> s){
        if(s=="+" || s=="*"){
            int b = w.top(); w.pop();
            int a = w.top(); w.pop();
            if(s=="+")
                w.push(a+b);
            else
                w.push(a*b);
        }else{
            w.push(stoi(s));
        }
    }
    cout << w.top() << endl;
    return 0;
}
