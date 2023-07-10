#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

// 故意用了递归，从效率考虑，应该用循环
int get_len(Node* head)
{
    if(head->next==NULL) return 0;
    return get_len(head->next) + 1;
}

// 插入 q 为 p 的后继
void insert_node(Node* p, Node* q)
{
    q->next = p->next;
    p->next = q;
}

// 查找,返回目标的前趋
Node* find_data(Node* head, int x)
{
    if(head->next==NULL) return NULL;
    if(head->next->data == x) return head;
    return find_data(head->next,x);
}

// 删除, p: 被删除节点的前趋，
// 返回被删除的节点
Node* del_node(Node* p)
{
    Node* q = p->next;
    p->next = q->next;
    return q;
}

// 删除所有节点
void del_all(Node* head)
{
    while(head->next) free(del_node(head));
}

void show(const Node* head)
{
    while(head->next){
        cout << head->next->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int a[8] = {2,8,5,3,5,4,9,8};
    Node head = Node{-1,NULL};

    for(int i=0; i<8; i++) insert_node(&head, new Node{a[i],NULL});
    cout << "len: " << get_len(&head) << endl;
    show(&head);
    free(del_node(find_data(&head,5)));
    free(del_node(&head));
    show(&head);

    del_all(&head);
    show(&head);

    return 0;
}
