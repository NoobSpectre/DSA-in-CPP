#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

int tree_diameter(Node *root, int &dia)
{
  if (root == NULL)
    return 0;

  int lh = tree_diameter(root->left, dia);
  int rh = tree_diameter(root->right, dia);

  dia = max(dia, lh + rh);

  return 1 + max(lh, rh);
}

int main()
{
  Node *root = NULL;

  insert(root, 35);
  insert(root, 30);
  insert(root, 40);
  insert(root, 25);
  insert(root, 32);
  insert(root, 20);
  insert(root, 28);

  cout << "Tree created!\n";

  int diameter = 0;
  tree_diameter(root, diameter);

  cout << "Diameter of the tree is: " << diameter << endl;

  return 0;
}