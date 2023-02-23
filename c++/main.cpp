#include<iostream>
using namespace std;

int main(){
	double c,h,k;
	cout << "c=" ;	
	cin>>c;
	cout << "h=" ;    
	cin>>h;
	k=9/5*h+32;	
	double F =9/5*c+32;
	//c++输出
	cout << "c++" << endl;
	cout << "f=" << F << endl;
	cout << "k=" << k << endl;
	//c输出
	printf("c\n");
	printf("f=%.2f\n",F);
	printf("k=%.2f\n",k);
	//%.2f：保留两位小数, \n换行
	return 0;
}
