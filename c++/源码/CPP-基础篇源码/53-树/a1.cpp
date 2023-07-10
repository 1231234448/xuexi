#include <iostream>

using namespace std;

struct Tree{
    int data;
    Tree* child;
    Tree* brother;
};

// 为 me 增加一个兄弟 br(other)
void add_brother(Tree* me, Tree* br)
{
    if(me->brother)
        add_brother(me->brother, br);
    else
        me->brother = br;
}

// 为 me 增加一个孩子 ch(ild)
void add_child(Tree* me, Tree* ch)
{
    if(me->child)
        add_brother(me->child, ch);
    else
        me->child = ch;
}

// 深度优先遍历
void dfs(Tree* p)
{
    cout << p->data << endl;
    if(p->child) dfs(p->child);
    if(p->brother) dfs(p->brother);
}

void del_tree(Tree* p)
{
    if(p->child) del_tree(p->child);
    if(p->brother) del_tree(p->brother);
    delete p;
}

int main()
{
    Tree* root = new Tree{0, NULL, NULL};
    Tree *p, *q, *r;
    p = new Tree{1, NULL, NULL}; add_child(root, p);
    q = new Tree{11, NULL, NULL}; add_child(p, q);
    q = new Tree{12, NULL, NULL}; add_child(p, q);
    p = new Tree{2, NULL, NULL}; add_child(root, p);
    q = new Tree{21, NULL, NULL}; add_child(p, q);
    q = new Tree{22, NULL, NULL}; add_child(p, q);
    r = new Tree{221, NULL, NULL}; add_child(q, r);
    q = new Tree{23, NULL, NULL}; add_child(p, q);
    p = new Tree{3, NULL, NULL}; add_child(root, p);

    dfs(root);

    del_tree(root);

    return 0;
}
