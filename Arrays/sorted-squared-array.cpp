#include <iostream>
#include <vector>
#include <climits>
#include "array_utilities.cpp"
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
  vector<int> ans;
  
  int pivot = 0, minVal = INT_MAX, n = nums.size();
  for(int i=0; i<n; i++) {
    if(nums[i] * nums[i] >= minVal) continue;
    pivot = i;
    minVal = nums[pivot] * nums[pivot];
  }

  ans.push_back(nums[pivot] * nums[pivot]);
  
  int left = pivot - 1, right = pivot + 1;
  while(ans.size() <= n) {
    if(left >= 0 && right < n) {
      if(nums[left] * nums[left] <= nums[right] * nums[right]) {
        ans.push_back(nums[left] * nums[left]);
        left--;
      } else {
        ans.push_back(nums[right] * nums[right]);
        right++;
      }
    } else if(left < 0 && right < n) {
      ans.push_back(nums[right] * nums[right]);
      right++;
    } else if(left >= 0 && right >= n) {
      ans.push_back(nums[left] * nums[left]);
      left--;
    }
  }
  
  return ans;
}

int main() {
  cout << "Enter the number of values: ";
  int n; cin >> n;

  vector<int> nums(n);
  cout << "Enter values: ";
  for(int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> result = sortedSquares(nums);

  cout << "The resultant array is: ";
  printVec(result);

  return 0;
}