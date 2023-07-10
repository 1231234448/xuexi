#include <iostream>
#include <string.h>

using namespace std;

void swap(char* p, char* q)
{
    char t = *p; *p = *q; *q = t;
}

void pai(char* buf, int k)
{
    int n = strlen(buf);
    if(k==n){
        printf("%s\n", buf);
        return;
    }

    for(int i=k; i<n; i++){
        swap(buf+k, buf+i);  //设置
        pai(buf, k+1);
        swap(buf+k, buf+i);  //恢复
    }
}

void pai(char* buf)
{
    pai(buf, 0);
}

int main()
{
    char buf[] = "abcd";
    pai(buf);
    return 0;
}
