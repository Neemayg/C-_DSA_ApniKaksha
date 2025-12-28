#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node*left;
  Node*right;

  Node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
  }

};

Node* insert(Node* root,int data){
  if(root == NULL){
    return new Node(data);
  }
  if(data<root->data){
    root->left=insert(root->left,data);
  }
  else{
    root->right=insert(root->right,data);
  }
  return root;
}

void inorder(Node* root){
  if (root==NULL){
    return;
  }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  
}


int main(){
  Node*root=NULL;
  root=insert(root,10);
  insert(root,20);
  insert(root,15);
  insert(root,5);
  insert(root,1);
  insert(root,63);
  insert(root,90);
  cout<<"Inorder traversal: "<<endl;
  inorder(root);
  return 0;
}