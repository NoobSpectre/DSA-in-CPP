/**
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
 * return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally
 * or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 * Input: grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 * Example 2:
 * Input: grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * Output: 3
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// using stack
// void dfs_stack(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
//   stack<pair<int, int>> s;
//   s.push({ row, col });
//   int row_limit = grid.size() - 1;
//   int col_limit = grid[0].size() - 1;

//   while (!s.empty()) {
//     int _row = s.top().first;
//     int _col = s.top().second;
//     s.pop();

//     if (!visited[_row][_col]) {
//       visited[_row][_col] = 1;

//       // traverse neighbours and check for land
//       for (int delta = -1; delta <= 1; delta++) {
//         if (delta == 0) continue;

//         int newRow = _row + delta;
//         int newCol = _col + delta;

//         if (newRow >= 0 && newRow <= row_limit && grid[newRow][_col] == '1' && !visited[newRow][_col]) {
//           s.push({ newRow, _col });
//         }

//         if (newCol >= 0 && newCol <= col_limit && grid[_row][newCol] == '1' && !visited[_row][newCol]) {
//           s.push({ _row, newCol });
//         }
//       }
//     }
//   }
// }

// using recursion
void dfs_recursion(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
  visited[row][col] = 1;
  int row_limit = grid.size() - 1;
  int col_limit = grid[0].size() - 1;

  for (int delta = -1; delta <= 1; delta++) {
    if (delta == 0) continue;

    int newRow = row + delta;
    int newCol = col + delta;

    if (newRow >= 0 && newRow <= row_limit && grid[newRow][col] == '1' && !visited[newRow][col]) {
      dfs_recursion(grid, visited, newRow, col);
    }

    if (newCol >= 0 && newCol <= col_limit && grid[row][newCol] == '1' && !visited[row][newCol]) {
      dfs_recursion(grid, visited, row, newCol);
    }
  }
}

int findNumberOfIslands(vector<vector<char>>& grid) {
  int rows = grid.size();
  int cols = grid[0].size();

  vector<vector<bool>> visited(rows, vector<bool>(cols, 0));

  int num_of_islands = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == '1' && !visited[i][j]) {
        num_of_islands++;
        dfs_recursion(grid, visited, i, j);
        // dfs_stack(grid, visited, i, j);
      }
    }
  }

  return num_of_islands;
}

int main() {
  cout << "Enter the number of testcases: ";
  int t; cin >> t;

  while (t--) {
    cout << "Enter the dimensions of the grid: ";
    int n, m; cin >> n >> m;

    cout << "Enter the lands below: " << endl;
    vector<vector<char>> grid(n, vector<char>(m, '0'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    cout << "The number of provinces are: " << findNumberOfIslands(grid) << endl;
  }

  return 0;
}