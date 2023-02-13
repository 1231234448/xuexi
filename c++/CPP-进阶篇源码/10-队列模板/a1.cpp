#include <iostream>

using namespace std;


template <typename T>
class Que{
public:
    Que() { front = back = NULL; }
    ~Que() {
        while(!empty()){ cout << "debug: " << remove() << endl; }
    }
    Que& add(const T& x);
    T remove();
    bool empty() { return front==NULL; }
private:
    class Node{
    public:
        Node(const T& x){ data = x; next=NULL; }
        T data;
        Node* next;
    };
private:
    Node* front;
    Node* back;
};


template <typename T>
Que<T>& Que<T>::add(const T& x)
{
    Node* p = new Node(x);
    if(empty())
        front = p;
    else
        back->next = p;
    back = p;
    return *this;
}

template <typename T>
T Que<T>::remove()
{
    if(empty()) throw -1;
    Node* p = front;
    front = front->next;
    if(front==NULL) back = NULL;

    T rt = p->data;
    delete p;
    return rt;
}

int main()
{
    Que<int> a;
    a.add(1).add(2).add(3);
    while(!a.empty()) cout << a.remove() << endl;
    a.add(4).add(5);

    return 0;
}
