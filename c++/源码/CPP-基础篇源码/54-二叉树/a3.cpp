#include <iostream>

using namespace std;

struct BiTree{
    int data;
    BiTree* left;
    BiTree* right;
};

int max(int a, int b){ return a>b? a : b; }
int get_height(BiTree* p)
{
    if(p==NULL) return 0;
    return max(get_height(p->left), get_height(p->right)) + 1;
}

void pre_order(BiTree* p)
{
    if(p==NULL){
        cout << -1 << ",";
        return;
    }
    cout << p->data << ",";
    pre_order(p->left);
    pre_order(p->right);
}

void in_order(BiTree* p)
{
    if(p==NULL) return;
    in_order(p->left);
    cout << p->data << " ";
    in_order(p->right);
}

void post_order(BiTree* p)
{
    if(p->left) post_order(p->left);
    if(p->right) post_order(p->right);
    cout << p->data << " ";
}

int create_tree(int* a, BiTree*& r)
{
    if(*a == -1){
        r = NULL;
        return 1;
    }

    r = new BiTree{*a};
    int n1 = create_tree(a+1, r->left);
    int n2 = create_tree(a+1+n1, r->right);
    return 1 + n1 + n2;
}

void destroy_tree(BiTree* r)
{
    if(r==NULL) return;
    destroy_tree(r->left);
    destroy_tree(r->right);
    delete r;
}

int main()
{
    int a[] = {1,2,4,-1,-1,5,9,-1,-1,-1,3,-1,6,7,-1,-1,8,-1,-1};
    BiTree* r;
    create_tree(a, r);

//    BiTree* r = new BiTree{1,NULL,NULL};
//    r->left = new BiTree{2,NULL,NULL};
//    r->right = new BiTree{3,NULL,NULL};
//    r->left->left = new BiTree{4,NULL,NULL};
//    r->left->right = new BiTree{5,NULL,NULL};
//    r->right->right = new BiTree{6,NULL,NULL};
//    r->right->right->left = new BiTree{7,NULL,NULL};
//    r->right->right->right = new BiTree{8,NULL,NULL};
//    r->left->right->left = new BiTree{9,NULL,NULL};

    cout << get_height(r) << endl;

    pre_order(r); cout << endl;
    in_order(r); cout << endl;
    post_order(r); cout << endl;

    destroy_tree(r);

    return 0;
}
