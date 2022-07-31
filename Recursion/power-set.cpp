/*

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
  Input: nums = [1,2,3]
  Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
  Input: nums = [0]
  Output: [[],[0]]

*/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, vector<vector<int> > &ans, vector<int> subset, int index) {
  //base case
  if(index >= nums.size()) {
    ans.push_back(subset);
    return;
  }

  //excluded case
  solve(nums, ans, subset, index + 1);

  //include case
  int element = nums[index];
  subset.push_back(element);
  solve(nums, ans, subset, index + 1);
}

vector<vector<int>> powerSet(vector<int>& nums) { // [1,2,3]
  vector<vector<int>> ans;
  if(nums.size() <= 0) return ans;

  vector<int> subset;
  solve(nums, ans, subset, 0);

  return ans;
}

int main() {
  cout << "Enter the number of integers in the array: ";
  int n; cin >> n;

  cout << "Enter the integers in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> power_set = powerSet(arr);

  cout << "Number of power set elements: " << power_set.size() << endl;

  cout << "[";
  for(int i=0; i<power_set.size(); i++) {
    cout << "[";
    for(int j=0; j<i; j++) {
      cout << power_set[i][j];
      if(j != i - 1) cout << ", ";
    }
    if(i != (power_set.size() - 1)) cout << "], ";
  }
  cout << "]";

  return 0;
}