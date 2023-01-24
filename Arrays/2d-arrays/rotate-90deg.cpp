#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>& matrix, int start, int end) {
  if(start >= end) return;
  for(int i=0; i<end - start; i++) {
    swap(matrix[start][start + i], matrix[start + i][end]);
    swap(matrix[start][start + i], matrix[end][end - i]);
    swap(matrix[start][start + i], matrix[end - i][start]);
  }
  solve(matrix, start + 1, end - 1);
}

void rotate_90_deg(vector<vector<int>>& matrix) {
  int n = matrix.size();
  solve(matrix, 0, n - 1);
  return;
}

void print_matrix(vector<vector<int>>& matrix) {
  for(int i=0; i<matrix.size(); i++) {
    for(int j=0; j<matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
  }
}

int main() {
  cout << "Enter the dimensions of the 2d-array: ";
  int n;
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(n, 0));
  cout << "Enter the values of the 2d-array: ";
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  rotate_90_deg(matrix);

  cout << "After 90 degrees rotation, the matrix is: ";
  print_matrix(matrix);

  return 0;
}