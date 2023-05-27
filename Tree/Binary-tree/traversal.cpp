#include <iostream>
#include <vector>
#include <queue>
#include "../TreeNode.cpp"
using namespace std;

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
    if(tmp -> left) q.push(tmp -> left);
    if(tmp -> right) q.push(tmp -> right);
    q.pop();
  }

  return;
}

vector<vector<int>> traverse_zigzag(Node *root) {
  vector<vector<int>> zigzag_nodesList;
  if(root == NULL) return zigzag_nodesList;

  queue<Node *> q;
  q.push(root);

  bool leftToRight = true;

  while(!q.empty()) {
    int n = q.size();
    vector<int> tmp(n);

    for(int i = 0; i < n; i++) {
      Node* front = q.front();

      if(leftToRight) {
        tmp[i] = front->data;
      } else {
        tmp[n - i - 1] = front->data;
      }

      if(front -> left) q.push(front -> left);
      if(front -> right) q.push(front -> right);

      q.pop();
    }
    
    zigzag_nodesList.push_back(tmp);
    leftToRight = !leftToRight;
  }

  return zigzag_nodesList;
}

void printNodes(vector<vector<int>> &vec) {
  if(!vec.size()) return;

  for(int i = 0; i < vec.size(); i++) {
    for(int j = 0; j < vec[i].size(); j++) {
      cout << vec[i][j] << " ";
    }
  }

  cout << endl;

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

  cout << "\nThe zigzag traversal of the tree is: ";
  vector<vector<int>> zigzagNodesList = traverse_zigzag(root);
  printNodes(zigzagNodesList);

  return 0;
}