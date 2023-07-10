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

class LinkStack:public IStack{
public:
    LinkStack() { head = NULL; }
    virtual LinkStack& push(IObj* x) override{
        head = new Node{x, head};
        return *this;
    }
    virtual IObj* pop() override{
        if(head==NULL) throw "empty pop!";
        Node* t = head;
        IObj* rt = t->data;
        head = head->next;
        delete t;
        return rt;
    }
    virtual bool empty() override{
        return head==NULL;
    }
private:
    struct Node{
        IObj* data;
        Node* next;
    };
private:
    Node* head;
};

struct Point: public IObj{
    Point():Point(0,0){}
    Point(int x, int y){this->x=x; this->y=y;}
    virtual void show(ostream& os) const override{
        os << "(" << x << "," << y << ")";
    }
    int x;
    int y;
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
        cout << s.pop() << endl;
    }
}

int main()
{
    LinkStack a;
    Point p1 = Point(1,1);
    Point* p2 = new Point(2,2);
    Point* p3 = new Point();  // = Point(0,0)

    a.push(&p1).push(p2).push(p3);

    clear(a);

    delete p2;
    delete p3;
    return 0;
}
