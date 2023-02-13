#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

// 故意用了递归，从效率考虑，应该用循环
int get_len(Node* head)
{
    if(head==NULL) return 0;
    return get_len(head->next) + 1;
}

// 在表头插入
Node* add_data(Node* head, int x)
{
    return new Node{x, head};
}

// 查找
Node* find_data(Node* head, int x)
{
    if(head==NULL) return NULL;
    if(head->data == x) return head;
    return find_data(head->next,x);
}

// 删除
Node* del_data(Node* head, int x)
{
    if(head==NULL) return NULL;
    if(head->data == x){
        Node* p = head->next;
        delete head;
        return p;
    }

    Node* p = head;
    while(p->next){
        if(p->next->data == x){
            Node* q = p->next;
            p->next = q->next;
            delete q;
            return head;
        }
        p = p->next;
    }
    return head;
}

void show(const Node* head)
{
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int a[8] = {2,8,5,3,5,4,9,8};
    Node* head = NULL;

    for(int i=0; i<8; i++) head = add_data(head, a[i]);
    cout << "len: " << get_len(head) << endl;
    show(head);
    cout << find_data(head, 5)->data << endl;
    head = del_data(head, 5);
    head = del_data(head, 8);
    show(head);

    // 至此。。。。 出现了 <内存泄漏> 问题
    return 0;
}
