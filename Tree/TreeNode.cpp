#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
  int data;
  Node *left, *right;

  Node(int val) {
    this->data = val;
    this->left = this->right = NULL;
  }
  Node(int *null) {}
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

// void insert(Node *root, string val) {
//   if(root == NULL) {
//     root = new Node(NULL);
//   }
//   else if
// }

void printNodes(const vector<vector<int>> &vec) {
  if(!vec.size()) return;

  int n = vec.size();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < vec[i].size(); j++) {
      cout << vec[i][j] << " ";
    }
  }

  cout << endl;
}