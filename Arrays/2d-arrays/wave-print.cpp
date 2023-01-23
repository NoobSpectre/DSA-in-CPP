/**
 * arr = {{1, 2}
 *        {3, 4}}
 *         ↓  ↑
 * wave print the arr will give the following: 1, 3, 4, 2
*/

#include<iostream>
#include<vector>
using namespace std;

void wave_print(vector<vector<int>>& arr, int n, int m) {
  cout << "The wave print of the given 2d-array is: ";
  int dir = 1;
  for (int cols = 0; cols < m; ++cols) {
    int rows = dir ? 0 : n - 1;
    while(rows >= 0 && rows < n) {
      cout << arr[rows][cols] << " ";
      dir ? rows++ : rows--;
    }
    dir ^= 1;
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

  wave_print(arr, n, m);

  return 0;
}

// Approach 2: Odd index column -> bottom to top, even index column -> top to bottom