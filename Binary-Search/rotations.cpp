/****************************************************************
 Suppose a sorted array is rotated x times(circular left shifts),
 i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2].
 Find x (0 <= x <= n-1). Assume no duplicates exist.
****************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int arrRotations(vector<int> arr, int n) {
    if(arr[0] < arr[n-1]) return 0;
    int s = 0, e = n-1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    
    while(s <= e) {
        if(arr[mid] > arr[mid + 1]) {
            ans = mid;
            break;
        }
        else {
            
        }

        mid = s + (e - s) / 2;
    }

    return (n - ans - 1);
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
        
        cout << "Rotations made on this array are: " << arrRotations(arr, n) << endl;
    }

    return 0;
}