#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int value = this->data;

        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data value: "<<value;
        cout<<endl;
    }
};

void insertAtHead(node* &head,int d){
    node*temp=new node(d);
    temp->next =head;
    head = temp;
}

void insertAtEnd(node* &tail,int d){
    node*temp = new node(d);
    tail->next=temp;
    tail = tail->next;
}

void insertAtPos(node* &head,node* &tail,int pos,int d){
    //insert at head
    node*newnode= new node(d);
    if(pos==1){
    //  newnode->next  = head;
    //  head = newnode;

    insertAtHead(head,d);
     return;
    }
    
    int cnt = 1;
    node*temp =head;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next ==NULL){
        insertAtEnd(tail,d);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return;

}

void deleteNode(node* &head,node* &tail,int pos){
  if(pos==1){
//delete head node
    node*temp = head;
     head = head->next;
     temp->next = NULL;

     delete temp;
  }else{
//delete end or any node
     node*prev = NULL;
     node*curr = head;
int cnt =1;
while(cnt<pos){
  prev = curr;
  curr = curr->next;
  cnt++;    
}
if(curr->next==NULL){
   tail = prev;
}
prev->next = curr->next;
curr->next=NULL;
delete curr;
  }
}

//print
void print(node* &head){
    node* temp =head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp =  temp->next;
  }
  cout<<endl;
}

int main(){
  node* node1 = new node(10);
  node*head = node1;
  node*tail = node1;
  print(head);
insertAtHead(head,12); 
 print(head);

 insertAtHead(head,13); 
 print(head);

 insertAtHead(head,15); 
 print(head);

 insertAtEnd(tail,22);
 print(head);

 insertAtEnd(tail,32);
 print(head);

 insertAtPos(head,tail,7,44);
 print(head);



 deleteNode(head,tail,7);
 print(head);

  cout<<"head data"<<head->data<<endl;
 cout<<"tail data"<<tail->data;

}