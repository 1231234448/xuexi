#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Que{
public:
    Que() { head=NULL; tail=NULL; }
    ~Que() { int x;  while(pop(x)); }
    Que& push(int x){
        Node* t = new Node(x);
        if(tail){
            tail->next = t;
            tail = t;
        }else{
            tail = t;
            head = t;
        }
        return *this;
    }
    bool pop(int& x){
        if(head==NULL) return false;
        Node* t = head;
        if(head==tail){
            head = NULL;
            tail = NULL;
        }else{
            head = t->next;
        }
        x = t->data;
        delete t;
        return true;
    }

private:
    Node* head;
    Node* tail;
};



int main()
{
    Que a;
    a.push(10).push(20).push(30);
    int x;
    while(a.pop(x)) cout << x << endl;

    return 0;
}
