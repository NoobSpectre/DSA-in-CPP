/*

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
  Input: nums = "abc"
  Output: [[],[a],[b],[c],[ab],[bc],[ac],[abc]]

Example 2:
  Input: nums = [a]
  Output: [[],[a]]

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string str, vector<string> &ans, string subsequence, int index) {
  //base case
  if(index >= str.size()) {
    ans.push_back(subsequence);
    return;
  }

  //excluded case
  solve(str, ans, subsequence, index + 1);

  //include case
  int element = str[index];
  subsequence.push_back(element);
  solve(str, ans, subsequence, index + 1);
}

vector<string> subsequence(string &str) { // abc
  vector<string> ans;
  if(str.size() <= 0) return ans;

  string subsequence;
  solve(str, ans, subsequence, 0);

  return ans;
}

int main() {
  cout << "Enter the string: ";
  string s; cin >> s;

  vector<string> subsequence_set = subsequence(s);

  cout << "Number of power set elements: " << subsequence_set.size() << endl;

  cout << "[";
  for(int i=0; i<subsequence_set.size(); i++) {
    cout << "[" << subsequence_set[i];
    if(i == (subsequence_set.size() - 1)) cout << "]";
    else cout << "], ";
  }
  cout << "]";

  return 0;
}