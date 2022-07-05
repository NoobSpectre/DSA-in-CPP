/****************************************************************
 Suppose a sorted array is rotated x times(circular left shifts),
 i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2].
 Find x (0 <= x <= n-1) (effective rotations). Assume no duplicates exist.
****************************************************************/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// function returns the index of the pivot (max element) of the rotated sorted array
int max_pivotIndex(vector<int> &arr, int n) {
	if(arr[0] < arr[n - 1] || n == 1)
		return (n - 1);
	
	int s = 0, e = n-1;
	int mid = (s + e) / 2;
	int ans = -1;
	if(arr[0] == arr[mid] && arr[mid] == arr[e])
		return (n - 1);
	else if(mid && arr[mid] < arr[mid - 1])
		return (mid - 1);
	int value = INT_MIN;

	while(s <= e) {
		if((mid == 0 || arr[mid] <= arr[mid - 1]) && arr[mid] >= arr[mid + 1] && arr[mid] >= value) {
			ans = mid;
			value = arr[ans];
			s = mid + 1;
		} else if(arr[n - 1] >= arr[mid])
			e = mid - 1;
		else s = mid + 1;

		mid = (s + e) / 2;
	}

	return ans;
}

// function returns the index of the pivot (min element) of the rotated sorted array
int min_pivotIndex(vector<int> &arr, int n) {
	if(arr[0] < arr[n - 1] || n == 1)
		return (n - 1);

	int s = 0, e = n-1;
	int mid = (s + e) / 2;
	int ans = -1;
	if(arr[0] == arr[mid] && arr[mid] == arr[e])
		return (n - 1);
	else if(mid && arr[mid] < arr[mid - 1])
		return (mid - 1);
	int value = INT_MIN;

	/********** remaining code to write ************/
	// while(s <= e) {
	// 	if()
	// }
}

int effectiveArrayRotations(vector<int> &arr, int n) {
  return (n - 1 - max_pivotIndex(arr, n));
}

int main() {
	cout << "Enter the number of testcases: ";
	int testcases; cin >> testcases;

	while(testcases--) {
		cout << "Enter the length of the array: ";
		int n; cin >> n;

		cout << "Enter the rotated sorted array: ";
		vector<int> arr(n);
		for(int i=0; i<n; i++)
				cin >> arr[i];
		
		cout << "Rotations made on this array are: " << effectiveArrayRotations(arr, n) << endl;
	}

	return 0;
}