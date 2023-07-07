#include <iostream>
#include <string.h>

using namespace std;

// 把一个绝对路径文件名，分为4个部分
bool splitpath(const char* s, char* buf, char**path,
              char** base, char** ext)
{
    char* p = strchr(s,':');
    if(p==NULL) return false;
    memcpy(buf, s, p-s);
    *path = buf + (p-s);
    *(*path)++ = '\0';

    char* q = strrchr(s,'\\');
    if(q==NULL) return false;
    memcpy(*path, p+1, q-p);
    *base = *path + (q-p);
    *(*base)++ = '\0';

    char* r = strrchr(s,'.');
    if(r==NULL) r = (char*)s + strlen(s);
    memcpy(*base, q+1, r-q-1);
    *ext = *base + (r-q-1);
    *(*ext)++ = '\0';

    if(*r)
        strcpy(*ext, r+1);
    else
        *ext = '\0';

    return true;
}


int main()
{
    char* s = "c:\\abc\\my\\path\\zhansan.back.txt";
    char buf[300];
    char* path;
    char* base;
    char* ext;
    splitpath(s, buf, &path, &base, &ext);
    cout << buf << endl;
    cout << path << endl;
    cout << base << endl;
    cout << ext << endl;


    return 0;
}
