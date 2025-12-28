#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node*next;

  Node(int data){
    this->data=data;
    this->next=NULL;
  };

};

void insertAtHead(Node* &head,int d){
  Node * temp=new Node(d);
  temp->next=head;
  head=temp;
}

void insertAtTail(Node* &tail,int d){
  Node * temp=new Node(d);
  tail->next=temp;
  tail=temp;
}

void deleteFromMiddle(Node* &head, int position) {

  // deleting first node
  if(position == 1){
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node* curr = head;
  Node* prev = NULL;

  int cnt = 1;
  while(cnt < position){
    prev = curr;
    curr = curr->next;
    cnt++;
  }

  prev->next = curr->next;
  delete curr;
}


void print(Node* &head){
  Node*temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

int main(){

  //create new node
  Node* node1=new Node(10);

  Node*head=node1;
  Node*tail=node1;

  print(head);
  insertAtHead(head,20);
  print(head);
  insertAtHead(head,30);
  print(head);
  insertAtTail(tail,40);
  print(head);
  insertAtTail(tail,50);
  print(head);
  deleteFromMiddle(head, 3);
  print(head);

  return 0;
}