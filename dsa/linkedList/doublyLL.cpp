#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~node()
    {
        int value = this->data;

        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data value: " << value;
        cout << endl;
    }
};

void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return;
}

void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(node *&head, node *&tail, int pos, int d)
{

    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    else
    {
        node *newnode = new node(d);
        node *temp = head;
        int cnt = 1;
        while (cnt < pos - 1)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(tail, d);
            return;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

// deletion
void deleteNode(node *&head, node *&tail, int pos)
{
    node *temp = head;
    if (pos == 1)
    {
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *prev = NULL;
        node *curr = head;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLen(node *&head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    print(head);
    insertAtHead(head, 12);
    print(head);

    /*insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 14);
    print(head);

    //  cout<<"length: "<<getLen(head);
    insertAtTail(tail, 22);
    print(head);

    insertAtTail(tail, 28);
    print(head);

    insertAtPos(head, tail, 3, 42);
    print(head);

    // cout<<"head : "<<head->data<<endl;
    // cout<<"tail : "<<tail->data;

    // deleteNode(head,tail, 3);
    // print(head);

    deleteNode(head, tail, 7);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data;*/
}