#include <iostream>
using namespace std;

class LinkNode{
public:
    LinkNode(){
        data = 0;
        next = NULL;
        cout << "..LinkNode().." << endl;
    }
    LinkNode(int x){
        data = x;
        next = NULL;
    }
    ~LinkNode(){
        cout << "..LinkNode...die..." << endl;
    }

    int get(){ return data; }

private:
    int data;
    LinkNode* next;
};

int main()
{
//    LinkNode a;
//    a = LinkNode{};
    LinkNode a;
    a = LinkNode{};
    return 0;
}
