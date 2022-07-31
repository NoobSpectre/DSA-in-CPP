#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, vector<vector<int> > &ans, int index) {
  //base case
  if(index >= nums.size()) {
    ans.push_back(nums);
    return;
  }

  for(int i = index; i < nums.size(); i++) {
    swap(nums[index], nums[i]);
    solve(nums, ans, index + 1);
    //backtrack
    swap(nums[index], nums[i]);
  }
}

vector<vector<int>> combinations(int n) { // n = 1234
  vector<vector<int>> ans;

  if (n < 0)
    return ans;

  vector<int> nums;
  while (n > 0) {
    nums.push_back(n % 10);
    n /= 10;
  }

  solve(nums, ans, 0);
  return ans;
}

int main() {
  cout << "Enter a number: ";
  int n; cin >> n;

  vector<vector<int>> result = combinations(n);

  cout << "Number of combinations: " << result.size() << endl;

  cout << "The combinations of the given number: ";
  for(auto i: result) {
    for(int j: i) {
      cout << j;
    }
    cout << " ";
  }

  return 0;
}