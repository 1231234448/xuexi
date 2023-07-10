#include <iostream>

using namespace std;

struct BiTree{
    int data;
    BiTree* left;
    BiTree* right;
};

void add(BiTree* r, int x)
{
    if(x < r->data)
        if(r->left)
            add(r->left, x);
        else
            r->left = new BiTree{x,NULL,NULL};
    else
        if(r->right)
            add(r->right, x);
        else
            r->right = new BiTree{x,NULL,NULL};
}

void inorder(BiTree* r)
{
    if(r==NULL) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void del_node(BiTree*& p)
{
    if(p->left==NULL){
        BiTree* t = p;
        p = p->right;
        delete t;
        return;
    }
    if(p->right==NULL){
        BiTree* t = p;
        p = p->left;
        delete t;
        return;
    }
    // 以下是左右子树都不空
    BiTree* pa = p;
    BiTree* s = p->left;
    while(s->right) {
        pa = s; // s“作死”之前，记住它的parent
        s = s->right;
    }
    p->data = s->data;  // 李代桃僵法

    if(pa==p) // 严谨！ 可能s就在p的脚边
        p->left = s->left;
    else
        pa->right = s->left;

    delete s; // s已无后顾之忧，删除之
}

bool del(BiTree*& r, int x)
{
    if(r==NULL) return false;
    if(x==r->data) {
        del_node(r);
        return true;
    }
    if(x < r->data)
        return del(r->left, x);
    else
        return del(r->right, x);
}




int main()
{
    int a[] = {12,5,18,6,4,20,9,15,16,22,7};
    BiTree* r = new BiTree{a[0], NULL, NULL};
    for(int i=1; i<sizeof(a)/4; i++) add(r, a[i]);

    inorder(r); cout << endl;

    del(r, 9);
    inorder(r); cout << endl;
    del(r, 12);
    inorder(r); cout << endl;

    return 0;
}
