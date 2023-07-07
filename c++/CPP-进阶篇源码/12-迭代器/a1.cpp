#include <iostream>

using namespace std;


class MyArray{
public:
    MyArray(){ size=10; data = new int[size]; n=0; }
    ~MyArray() { delete [] data; }
    void add(int x){
        if(n==size){
            int* old = data;
            data = new int[size * 2];
            memcpy(data,old,size * sizeof(int));
            delete [] old;
            size *= 2;
        }
        data[n++] = x;
    }

public:
    typedef int* Iter;
    Iter iter() { return data; }
    Iter end() { return data + n; }
private:
    int size; // 初始大小
    int n;  // 已有元素个数
    int* data;
};


class MyBlock{
public:
    MyBlock() { tail = head = new Node(); }
    ~MyBlock() {
        while(head){
            Node* p = head;
            delete [] p;
            head = head->next;
        }
    }
    void add(int x){
        if(head->n == BLOCK_SIZE) {
            Node* p = new Node();
            tail->next = p;
            tail = p;
        }
        tail->data[tail->n++] = x;
    }

public:
    struct Node;
    class Iter{
    public:
        Iter(Node* it, int n){
            this->it = it;
            this->p = it->data + n;
        }
        int operator* () { return *p; }
        void operator++(int) {
            p++;
            if(p==it->data + it->n && it->next){
                it = it->next;
                p = it->data;
            }
        }
        bool operator!= (const Iter& that){
            if(this->it != that.it) return true;
            if(this->p != that.p) return true;
            return false;
        }
    private:
        Node* it;  //当前块
        int* p; // 当前位置

    };
    Iter iter() { return Iter(head, 0); }
    Iter end() { return Iter(tail, tail->n); }
public:
    static const int BLOCK_SIZE = 10;
    struct Node{
        Node() { n=0; next=NULL; }
        int data[BLOCK_SIZE];
        int n;
        Node* next;
    };
private:
    Node* head;
    Node* tail;
};


int main()
{
    MyArray a;
    MyBlock b;
    for(int i=0; i<50; i++){
        a.add(i);
        b.add(i);
    }

    for(MyArray::Iter i=a.iter(); i!=a.end(); i++)
        cout << "a: " << *i << endl;

    for(MyBlock::Iter i=b.iter(); i!=b.end(); i++)
        cout << "b: " << *i << endl;

    return 0;
}
