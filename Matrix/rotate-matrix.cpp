#include<iostream>
#include<vector>
#include "./array_utilities.cpp"
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

void rotate_matrix(vector<vector<int>>& matrix, int num_of_rotations = 1, bool anti_clockwise = false) {
  int n = matrix.size();
  int is_rotations_possible = num_of_rotations >= 0;

  if(!is_rotations_possible) {
    cout << "Number of rotations can not be negative...!!!";
    return;
  }

  int rotations = num_of_rotations % 4;

  if(anti_clockwise) {
    rotations = ((num_of_rotations + (num_of_rotations + 4)) / 2) % 4;
  }

  for (int i = 0; i < rotations; i++) {
    solve(matrix, 0, n - 1);
  }

  return;
}

int main() {
  cout << "Enter the dimensions of the matrix: ";
  int n;
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(n));
  cout << "Enter the values of the matrix: ";
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  cout << "Before rotation, the matrix is: \n";
  print_matrix(matrix);

  int num_of_rotations = 7;
  bool anti_clockwise = false;

  rotate_matrix(matrix, num_of_rotations, anti_clockwise);

  cout << "After rotation(s), the matrix is: \n";
  print_matrix(matrix);

  return 0;
}