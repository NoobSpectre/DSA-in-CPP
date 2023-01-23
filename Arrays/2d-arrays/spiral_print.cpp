/**
 * arr = {{1, 2, 3},   →
 *        {4, 5, 6},  ↑ ↓
 *        {7, 8, 9}}   ←
 *
 * wave print the arr will give the following: 1, 2, 3, 6, 9, 8, 7, 4, 5
*/

#include<iostream>
#include<vector>
using namespace std;

void spiral_print(vector<vector<int>>& arr, int n, int m) {
  int left = 0, right = m - 1, top = 0, bottom = n - 1;
  while(left <= right && top <= bottom) {
    for (int i = left; i <= right; i++) {
      cout << arr[top][i] << " ";
    } top++;
    if(!(left <= right && top <= bottom)) break;
    for (int i = top; i <= bottom; i++) {
      cout << arr[i][right] << " ";
    } right--;
    if(!(left <= right && top <= bottom)) break;
    for (int i = right; i >= left; i--) {
      cout << arr[bottom][i] << " ";
    } bottom--;
    if(!(left <= right && top <= bottom)) break;
    for (int i = bottom; i >= top; i--) {
      cout << arr[i][left] << " ";
    } left++;
  }
  return;
}

int main() {
  cout << "Enter the dimensions of the 2d-array: ";
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  cout << "Enter the values of the 2d-array: ";
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  cout << "The spiral print of the given 2d-array is: ";
  spiral_print(arr, n, m);

  return 0;
}