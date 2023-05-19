#include<iostream>
#include "TreeNode.cpp"
using namespace std;

void zigzagTraversal();

int main() {
  Node *root = NULL;

// tree
  insert(root, 30);
  insert(root, 15);
  insert(root, 10);
  insert(root, 20);
  insert(root, 40);
  insert(root, 5);
  insert(root, 45);
  insert(root, 35);

  cout << "Tree created!\n";

  

  return 0;
}