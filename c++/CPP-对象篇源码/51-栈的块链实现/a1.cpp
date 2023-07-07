#include <iostream>

using namespace std;

struct IObj{
    virtual ~IObj(){}
    virtual void show(ostream& os) const = 0;
};

struct IStack{
    virtual ~IStack() {}
    virtual IStack& push(IObj*) = 0;
    virtual IObj* pop() = 0;
    virtual bool empty() = 0;
};

class BlockStack:public IStack{
public:
    BlockStack() { head = NULL; }
    ~BlockStack() { while(!empty()) delete pop(); }
    virtual BlockStack& push(IObj* x) override{
        if(head==NULL || head->n==BS) {
            Node* t = new Node();
            t->next = head;
            head = t;
        }
        head->data[head->n++] = x;
        return *this;
    }
    virtual IObj* pop() override{
        if(head==NULL) throw "empty pop!";
        IObj* rt = head->data[--head->n];
        if(head->n==0){
            Node* t = head;
            head = t->next;
            delete t;
        }
        return rt;
    }
    virtual bool empty() override{
        return head == NULL;
    }
private:
    static const int BS = 5;
    struct Node{
        Node() { n=0; next=NULL; }
        IObj* data[BS];
        int n;
        Node* next;
    };
private:
    Node* head;
};

struct MyInt: public IObj{
    MyInt(int x){ this->x = x; }
    virtual void show(ostream& os) const override{
        os << x;
    }
    int x;
};

ostream& operator<<(ostream& os, IObj* p)
{
    p->show(os);
    return os;
}

// 面向接口编程，不了解底层实现方式
void clear(IStack& s)
{
    while(!s.empty()){
        IObj* p = s.pop();
        cout << p << endl;
        delete p;
    }
}

int main()
{
    BlockStack a;
    for(int i=0; i<100; i++) a.push(new MyInt(i));

   // clear(a);

    return 0;
}
