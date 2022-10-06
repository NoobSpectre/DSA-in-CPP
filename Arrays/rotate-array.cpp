#include<iostream>
#include<vector>
#include "array_utilities.cpp"
using namespace std;

void reverse_vector(vector<int>& v, int beg, int end) {
  if(beg >= end) return;

  while(beg < end) {
    swap(v[beg], v[end]);
    beg++;
    end--;
  }

  return;
} 

void rotate(vector<int>& nums, int k) { // [1, 2, 3, 4, 5, 6, 7], k = 3 => [5, 6, 7, 1, 2, 3, 4]
  int n = nums.size();
  k = k % n;
  if(nums.size() == 1 || !k) return;

  reverse_vector(nums, 0, n - 1);
  reverse_vector(nums, 0, k - 1);
  reverse_vector(nums, k, n - 1);

  return;
}

int main() {
  cout << "Enter the number of elements: ";
  int n; cin >> n;

  vector<int> nums(n);
  cout << "Enter values: ";
  for(int i=0; i<n; i++) {
    cin >> nums[i];
  }

  cout << "Enter number of rotations to perform: ";
  int k; cin >> k;

  rotate(nums, k);

  cout << "The resultant array is: ";
  printVec(nums);

  return 0;
}