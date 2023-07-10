#include <iostream>
using namespace std;

class LinkNode{
public:
    LinkNode(int x){
        data = x;
        next = NULL;
    }
    ~LinkNode(){
        cout << "destroy... " << endl;
        if(next) delete next;
        next = NULL;
    }
    LinkNode& add(int x){
        LinkNode* p = new LinkNode(x);
        p->next = next;
        next = p;
        return *p;
    }
    void show(){
        LinkNode* p = this;
        while(p){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
private:
    int data;
    LinkNode* next;
};

int main()
{
    LinkNode head(-1);
    head.add(1).add(2).add(3);
    head.show();

    return 0;
}
