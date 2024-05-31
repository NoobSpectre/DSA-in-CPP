/**
 * There are n cities. Some of them are connected, while some are not. If city a is connected directly * with city b, and city b is connected directly with city c, then city a is connected indirectly with * city c.
 *
 * A province is a group of directly or indirectly connected cities and no other cities outside of the * group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth * * city are directly connected, and isConnected[i][j] = 0 otherwise.
 *
 * Return the total number of provinces.
 *
 * Example 1:
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 * Example 2:
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
  visited[node] = 1;

  for (auto it : graph[node]) {
    if (!visited[it]) {
      dfs(graph, visited, it);
    }
  }

  return;
}

int findNumberOfProvinces(vector<vector<int>>& isConnected) {
  int n = isConnected.size();
  vector<vector<int>> adjList(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && isConnected[i][j] == 1) {
        adjList[i].push_back(j);
        adjList[j].push_back(i);
      }
    }
  }

  int num_of_provinces = 0;
  vector<bool> visited(n, 0);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      num_of_provinces++;
      dfs(adjList, visited, i);
    }
  }

  return num_of_provinces;
}

int main() {
  cout << "Enter the number of testcases: ";
  int t; cin >> t;

  while (t--) {
    cout << "Enter number of cities: ";
    int n; cin >> n;

    cout << "Enter the connectivity below: " << endl;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> isConnected[i][j];
      }
    }

    cout << "The number of provinces are: " << findNumberOfProvinces(isConnected) << endl;
  }

  return 0;
}