
#include<iostream>

using namespace std;

int main()

{

int qiuhe(int x);

int n,s=0;

cout<<"请输入一个整数"<<endl;

cin>>n;

s=qiuhe(n);

cout<<s<<endl;

}

int qiuhe(int x)

{

    int sum=0;

    for(int i=0;i<=x;i++)

    sum+=i*i;

    return sum;

}

