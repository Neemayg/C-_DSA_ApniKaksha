#include<iostream>
using namespace std;

  struct node{
    int key;
    int height;
    node *left;
    node *right;

    node(int k){
      key=k;
      height==1;
      left,right=NULL;
    }
  };
  int height (node *n){
    return n ? n->height : 0;
  }
  int max(int a, int b){
    return(a>b) ? a:b;
  }
  int heightbalance(node *n){
    return n ? height(n->left) - height(n->right) : 0;
  }
  node * right_rotate(node *y){
    node *x=y->left;
    node *t2=x->right;
    y->left=t2;
    x->right=y;
    x->height=1+max(height(x->left), height(x->right));
    y->height=1+max(height(y->left), height(y->right));
    return x;
  }

   node * left_rotate(node *x){
    node *y=x->right;
    node *t2=y->left;
    x->right=t2;
    y->left=y;
    x->height=1+max(height(x->left), height(x->right));
    y->height=1+max(height(y->left), height(y->right));
    return y;
  }

  