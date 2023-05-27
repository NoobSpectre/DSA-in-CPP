#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "../TreeNode.cpp"
using namespace std;

void findModesInTree(Node *root, unordered_map<int, int> &modesMap) {
  if(root == NULL) return;

  modesMap[root -> data]++;
  findModesInTree(root -> left, modesMap);
  findModesInTree(root -> right, modesMap);
}

vector<int> findModes(Node *root) {
  vector<int> modes;
  if(root == NULL) return modes;

  unordered_map<int, int> modesMap;

  findModesInTree(root, modesMap);
  
  int max = INT_MIN;

  //1. using max_element and lambda function
  // here unordered_map<int, int>::iterator pr = auto pr
  // auto pr = max_element(modesMap.begin(), modesMap.end(), [](const auto &x, const auto &y) {
  //             return x.second < y.second;
  //           });
  // max = pr -> second;

  //2. using loops
    for (const auto &entry: modesMap) {
      if (max < entry.second) {
        max = entry.second;
      }
    }

  for(const auto &pr: modesMap) {
    if(pr.second == max) modes.push_back(pr.first);
  }

  return modes;
}

void printModes(const vector<int> &vec) {
  if(!vec.size()) return;

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

int main() {
  Node *root = NULL;

  // insert(root, 35);
  // insert(root, 30);
  // insert(root, 40);
  // insert(root, 25);
  // insert(root, 32);
  // insert(root, 20);
  // insert(root, 28);

  insert(root, 1);
  insert(root, 2);
  // insert(root, 2);

  cout << "Tree created!\n";

  vector<int> modes = findModes(root);

  cout << "The mode(s) of the given tree is/are: ";
  sort(modes.begin(), modes.end());
  printModes(modes);

  return 0;
}