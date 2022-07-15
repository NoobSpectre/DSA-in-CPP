#include <iostream>
using namespace std;

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
    return;
  }
  else if(root->data > val) {
    if(root->left == NULL) {
      Node *tmp = new Node(val);
      root->left = tmp;
      return;
    } else insert(root->left, val);
  } else {
    if(root->right == NULL) {
      Node *tmp = new Node(val);
      root->right = tmp;
      return;
    } else insert(root->right, val);
  }
}

void inOrder(Node *&root) {
  if(root == NULL) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(Node* &root) {
  if(root == NULL) return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node* &root) {
  if(root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int main() {
  Node *root = NULL;

  insert(root, 30);
  insert(root, 15);
  insert(root, 10);
  insert(root, 20);
  insert(root, 40);
  insert(root, 5);
  insert(root, 45);
  insert(root, 35);

  cout << "Tree created!";

  cout << "\nThe inorder traversal of the tree is: ";
  inOrder(root);

  cout << "\nThe preorder traversal of the tree is: ";
  preOrder(root);

  cout << "\nThe postorder traversal of the tree is: ";
  postOrder(root);

  return 0;
}