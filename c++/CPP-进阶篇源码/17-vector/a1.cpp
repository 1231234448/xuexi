#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x[] = {10,20,30};
    vector<int> a;  // size为 0
    vector<int> b(5);  // 指定初始大小，元素随机值
    vector<int> c(5,9);  // 5个元素，每个都是9
    vector<int> d(c);  // 拷贝构造
    vector<int> e(d.begin(), d.end());  //重要，通过另一个容器构造自己
    vector<int> f(x,x+3);  //真假指针通吃

    cout << b[2] << endl;
    cout << c[2] << endl;
    cout << e[2] << endl;
    cout << f[2] << endl;


    return 0;
}
