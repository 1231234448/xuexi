#include <iostream>

using namespace std;

class LinkNode{
public:
    int data;
    LinkNode* next;
    void add(LinkNode* it){
        it->next = next;
        next = it;
    }
    void clear(){
        if(next==NULL) return;
        next->clear();
        delete next;
        next = NULL;
    }
    void show(){
        cout << data << " ";
        if(next) next->show();
    }
    LinkNode copy();  // 深度拷贝
    LinkNode* f(){ LinkNode x; return &x; }
};


LinkNode LinkNode::copy()
{
    LinkNode t = {data, NULL};
    LinkNode* p = next;
    LinkNode* q = &t;
    while(p){
        q->next = new LinkNode{p->data, NULL};
        p = p->next;
        q = q->next;
    }
    return t;
}

int main()
{
    LinkNode a = {-1,NULL};
    for(int i=9; i>=1; i--) a.add(new LinkNode{i,NULL});

    //LinkNode b = a;
    LinkNode b = a.copy();
    b.show(); cout << endl;
    a.clear();
    b.show(); cout << endl;
    b.clear();

    return 0;
}
