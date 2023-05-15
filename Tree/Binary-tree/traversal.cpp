#include <iostream>
#include <queue>
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

// root value -> left child subtree -> right child subtree
void preOrder(Node* &root) {
  if(root == NULL) return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// left child subtree -> root value -> right child subtree
void inOrder(Node *&root) {
  if(root == NULL) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

// left child subtree -> right child subtree -> root value
void postOrder(Node* &root) {
  if(root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

// level order traversal
void levelOrder(Node* &root) {
  if(root == NULL) return;

  queue<Node *> q;
  q.push(root);

  while(!q.empty()) {
    Node *tmp = q.front();
    cout << tmp -> data << " ";
    if(tmp -> left != NULL) q.push(tmp -> left);
    if(tmp -> right != NULL) q.push(tmp -> right);
    q.pop();
  }

  return;
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

  cout << "\nThe levelorder traversal of the tree is: ";
  levelOrder(root);

  return 0;
}