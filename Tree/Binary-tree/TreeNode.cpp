#include <iostream>
// using namespace std;

class Node {
  public:
  int data;
  Node *left, *right;

  Node(int val) {
    this->data = val;
    this->left = this->right = NULL;
  }
};

void insert(Node* &root, int val) {
  if(root == NULL) {
    root = new Node(val);
  }
  else if(root->data > val) {
    if(root->left == NULL) {
      Node *tmp = new Node(val);
      root->left = tmp;
    } else insert(root->left, val);
  } else {
    if(root->right == NULL) {
      Node *tmp = new Node(val);
      root->right = tmp;
    } else insert(root->right, val);
  }

  return;
}