#include <iostream>
#include "TreeNode.cpp"
using namespace std;

int isBalancedTree(Node *&root)
{
  if (root == NULL)
    return 0;

  int leftChild = isBalancedTree(root->left);
  int rightChild = isBalancedTree(root->right);

  if (leftChild == -1 && rightChild == -1)
    return -1;
  else if (abs(leftChild - rightChild) > 1)
    return -1;

  return max(leftChild, rightChild) + 1;
}

int main()
{
  Node *root = NULL;

// Balanced tree
  // insert(root, 30);
  // insert(root, 15);
  // insert(root, 10);
  // insert(root, 20);
  // insert(root, 40);
  // insert(root, 5);
  // insert(root, 45);
  // insert(root, 35);

// Unbalanced tree
  insert(root, 35);
  insert(root, 30);
  insert(root, 40);
  insert(root, 25);
  insert(root, 32);
  insert(root, 20);
  insert(root, 28);

  cout << "Tree created!\n";

  cout << "Is Tree Balanced? " << (isBalancedTree(root) == -1 ? "Un-Balanced" : "Balanced") << endl;

  return 0;
}