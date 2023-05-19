#include <iostream>
#include "TreeNode.cpp"
using namespace std;

int maxPathSum(Node *root, int &max_path_sum)
{
  if (root == NULL)
    return 0;

  int lh = maxPathSum(root->left, max_path_sum);
  int rh = maxPathSum(root->right, max_path_sum);

  max_path_sum = max(max_path_sum, lh + rh + root->data);

  return max(lh, rh) + root->data;
}

int main()
{
  Node *root = NULL;

  // insert(root, 35);
  // insert(root, 30);
  // insert(root, 40);
  // insert(root, 25);
  // insert(root, 32);
  // insert(root, 20);
  // insert(root, 28);

  insert(root, 30);
  insert(root, 15);
  insert(root, 10);
  insert(root, 20);
  insert(root, 40);
  insert(root, 5);
  insert(root, 45);
  insert(root, 35);

  cout << "Tree created!\n";

  int max_path_sum = 0;
  maxPathSum(root, max_path_sum);

  cout << "Maximum path sum of the tree is: " << max_path_sum << endl;

  return 0;
}