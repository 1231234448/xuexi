#include <iostream>

using namespace std;

struct BiTree{
    int data;
    BiTree* left;
    BiTree* right;
};

void adj(BiTree*& r);
void add(BiTree*& r, int x)
{
    if(x < r->data)
        if(r->left)
            add(r->left, x);
        else
            r->left = new BiTree{x, NULL, NULL};
    else
        if(r->right)
            add(r->right, x);
        else
            r->right = new BiTree{x, NULL, NULL};
    //adj(r);
}

void inorder(BiTree* r)
{
    if(r==NULL) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

inline int max(int a, int b){ return a>b? a : b; }
// 树的高度
int h(BiTree* r)
{
    if(r==NULL) return 0;
    return max(h(r->left), h(r->right)) + 1;
}
//平衡因子
int balance(BiTree* r)
{
    return h(r->left) - h(r->right);
}

//校正过程
void adj(BiTree*& r)
{
    if(balance(r)<2) return;
    if(balance(r)>0){
        if(balance(r->left)>0){  //左左型
            BiTree* p = r;
            BiTree* q = p->left;
            r = q;
            p->left = q->right;
            q->right = p;
        }
        else{ // 左右型
            BiTree* p = r;
            BiTree* q = p->left;
            BiTree* s = q->right;
            r = s;
            q->right = s->left;
            p->left = s->right;
            s->left = q;
            s->right = p;
        }
    }
    else{
        if(balance(r->right)<0){  //右右型
            BiTree* p = r;
            BiTree* q = p->right;
            r = q;
            p->right = q->left;
            q->left = p;
        }
        else{ // 右左型
            BiTree* p = r;
            BiTree* q = p->right;
            BiTree* s = q->left;
            r = s;
            q->left = s->right;
            p->right = s->left;
            s->right = q;
            s->left = p;
        }
    }
}

int main()
{
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    BiTree* r = new BiTree{a[0], NULL, NULL};
    for(int i=1; i<sizeof(a)/4; i++) add(r, a[i]);

    inorder(r); cout << endl;
    cout << h(r) << endl;

    return 0;
}
