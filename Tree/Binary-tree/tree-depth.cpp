#include <iostream>
#include "../TreeNode.cpp"
using namespace std;

int tree_depth(Node *&root)
{
  if (root == NULL)
    return 0;

  return 1 + max(tree_depth(root->left), tree_depth(root->right));
}

int main()
{
  Node *root = NULL;

  insert(root, 30);
  insert(root, 15);
  insert(root, 10);
  insert(root, 20);
  insert(root, 40);
  insert(root, 5);
  insert(root, 45);
  insert(root, 35);

  cout << "Tree created!\n";

  cout << "Depth of the tree is: " << tree_depth(root) << endl;

  return 0;
}