#include <iostream>
using namespace std;


class Que{
public:
    class Node{
    public:
        Node(int x){ data = x; next = NULL; }
        Node* copy(){ return new Node(data); }
        void show(){ cout << data; }
    private:
        int data;
        Node* next;
        friend class Que;
    };

public:
    Que() { head=NULL; tail=NULL; }
    Que(Que& t):Que(){ copy(t); }
    ~Que() { clear(); }

    void clear(){ Node* p; while(p=pop()){ delete p; } }
    void copy(Que& t){
        for(Node* p=head; p; p=p->next) push(p->copy());
    }
    Que& operator=(Que& t){
        clear();
        copy(t);
        return *this;
    }

    Que& push(Node* p){
        if(tail){
            tail->next = p;
            tail = p;
        }else{
            tail = p;
            head = p;
        }
        return *this;
    }
    Node* pop(){
        if(head==NULL) return NULL;
        Node* t = head;
        head = t->next; t->next = NULL;
        if(head==NULL) tail = NULL;
        return t;
    }
    void show(){
        for(Node* p=head; p; p=p->next){
            p->show(); cout << " ";
        }
    }

private:
    Node* head;
    Node* tail;
};


int main()
{
    Que a;
    a.push(new Que::Node(10));
    a.push(new Que::Node(20));
    a.push(new Que::Node(30));
    Que b;
    b.push(new Que::Node(100));
    b.push(new Que::Node(200));

    delete b.pop();
    a.push(b.pop());
    a.show(); cout << endl;


    return 0;
}
