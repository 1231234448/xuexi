#include <iostream>
using namespace std;

int main()
{
int a=5,b=2,c=8;
    if(a>b)
    {
        if(b>c)
            cout<<b<<endl;
        else
         if(c>a) cout<<a<<endl;
        else    cout<<c<<endl;
    }
    else{
        if(b<c) cout<<b<<endl;
        else
         if(c<a)cout<<a<<endl;
        else     cout<<c<<endl;
    }
}

