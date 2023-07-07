#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

int get_len(Node* head)
{
    Node* p = head->next;
    int n = 0;
    while(p != head){
        n++;
        p = p->next;
    }
    return n;
}

// 插入 q 为 p 的前趋
void insert_node(Node* p, Node* q)
{
    Node* t = p->prev;
    q->prev = t;
    q->next = p;
    t->next = q;
    p->prev = q;
}

// 查找,返回目标节点
Node* find_data(Node* head, int x)
{
    Node* p = head->next;
    while(p!= head){
        if(p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

// 删除: p
Node* del_node(Node* p)
{
    Node* p1 = p->prev;
    Node* p2 = p->next;
    p1->next = p2;
    p2->prev = p1;
    return p;
}

// 删除所有节点(释放空间)
void del_all(Node* head)
{
    while(head->next!=head) free(del_node(head->next));
}

void show(const Node* head)
{
    Node* p = head->next;
    while(p!=head){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int a[8] = {2,8,5,3,5,4,9,8};
    Node head = {-1,&head,&head};

    for(int i=0; i<8; i++)
        insert_node(&head, new Node{a[i],NULL,NULL});
    cout << "len: " << get_len(&head) << endl;
    show(&head);
    free(del_node(find_data(&head,5)));
    free(del_node(head.next));
    show(&head);

    del_all(&head);
    show(&head);

    return 0;
}
