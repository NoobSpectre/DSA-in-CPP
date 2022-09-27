#include<iostream>
#include<vector>
#include "array_utilities.cpp"
using namespace std;

void moveZeros_toEnd(vector<int>& nums) {
  int n = nums.size();
  if(n == 1)
    return;

  int count = 0;
  for (int i = 0; i < n; i++) {
    if(nums[i]) nums[count++] = nums[i];
  }

  while(count < n) {
    nums[count++] = 0;
  }
}

int main() {
  cout << "Enter the number of elements: ";
  int n; cin >> n;

  cout << "Enter the elements: ";
  vector<int> nums(n);
  for(int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  moveZeros_toEnd(nums);

  printVec(nums);

  return 0;
}