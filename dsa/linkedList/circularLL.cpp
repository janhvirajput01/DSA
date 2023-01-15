#include<iostream>
using namespace std; 
class node{
    public:
    int data;
    node*next;
    
    node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertNode(node* &tail,int element,int d){

if(tail==NULL){
    //list is empty
     node*newNode= new node(d);
     tail= newNode;
     newNode->next = tail;
     return;
}else{
    node*newNode= new node(d);
    node*temp = tail;
    while(temp->data!=element){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next=newNode;
}
}

void deleteNode(node* &tail,int element){

if(tail == NULL){
    cout<<"list is  empty cannot delete";
}else{
    //non-empty list

    node*prev = tail;
    node*curr = prev->next;
    
if(curr==prev){
    //single node
    tail=NULL;
    return;
}
    while(curr->data!= element){
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    if(tail==curr){
        tail = prev;
    }
    curr->next=NULL;

    delete curr;
}
}

void print(node* &tail){
  node*temp = tail;
   if(tail==NULL){
    cout<<"list is empty";
    return;
}

  do{
  cout<<temp->data<<" ";
  temp= temp->next;
  }while(temp!=tail);
  cout<<endl;
}

bool isCircularLL(node* head){
    if(head==NULL){
    
        return true;
    }
    node*temp  = head->next;
    while(temp!=NULL&& temp!=head){
        temp=temp->next;
    }
      if(temp==NULL){
    
        return false;
      }

      if(temp==head){
   
        return true;
      }
}
int main(){
    node*tail = NULL;

    insertNode(tail,4,5);
    print(tail);

    insertNode(tail,5,4);
    print(tail);

if(isCircularLL(tail)){
    cout<<"YES";
}else{
    cout<<"NO";
}
    // insertNode(tail,5,3);
    // print(tail);

    // insertNode(tail,4,2);
    // print(tail);

    // deleteNode(tail,5);
    // print(tail);
}