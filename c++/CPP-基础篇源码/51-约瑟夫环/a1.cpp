#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void add(Node* p, Node* q)
{
    q->next = p->next;
    p->next = q;
}

void show(Node* head)
{
    Node* p = head->next;
    while(p!=head){
        cout << p->data << " ";
        p = p->next;
    }
    cout << head->data << endl;
}



int main()
{
    int n = 10;
    Node* p = new Node{n,NULL};
    p->next = p;

    for(int i=n-1; i>=1; i--) add(p, new Node{i,NULL});
    show(p);

    for(int i=0; i<n-1; i++){
        p = p->next;
        p = p->next;
        Node* t = p->next;
        p->next = t->next;
        delete t;
    }

    cout << p->data << endl;
    delete p;

    return 0;
}
