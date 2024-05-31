#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void bfs_traversal(vector<vector<int>>& graph, int nodes, bool based1 = 0) {
  queue<int> q;
  vector<bool> visited(nodes + 1, 0);

  if (based1) {
    q.push(1);
    visited[1] = 1;
  } else {
    q.push(0);
    visited[0] = 1;
  }

  cout << "The graph is: ";

  while (!q.empty()) {
    int node = q.front();

    cout << node << " ";
    q.pop();

    for (auto it : graph[node]) {
      if (!visited[it]) {
        visited[it] = 1;
        q.push(it);
      }
    }
  }

  cout << endl;
}

void dfs_recursion(vector<vector<int>>& graph, vector<bool>& visited, int node) {
  visited[node] = 1;
  cout << node << " ";

  for (auto it : graph[node]) {
    if (!visited[it]) {
      dfs_recursion(graph, visited, it);
    }
  }
}

// using recursion
void dfs_traversal(vector<vector<int>>& graph, int nodes, bool based1 = 0) {
  vector<bool> visited(nodes + 1, 0);

  int startNode = 0;
  if (based1) {
    visited[1] = 1;
    startNode = 1;
  } else {
    visited[0] = 1;
  }

  cout << "The graph is: ";

  dfs_recursion(graph, visited, startNode);
  cout << endl;
}

// using stack
void traverse_dfs(vector<vector<int>>& graph, int nodes, bool based1 = 0) {
  vector<bool> visited(nodes + 1, 0);
  stack<int> s;

  if (based1) {
    s.push(1);
  } else {
    s.push(0);
  }

  cout << "The graph is: ";

  while (!s.empty()) {
    int node = s.top();
    s.pop();

    if (visited[node]) continue;

    cout << node << " ";
    visited[node] = 1;

    for (auto it : graph[node]) {
      s.push(it);
    }
  }

  cout << endl;
}

void addEdge(vector<vector<int>>& graph, int srcNode, int destNode) {
  graph[srcNode].push_back(destNode);
  graph[destNode].push_back(srcNode);
}

int main() {
  // Number of nodes in the graph
  int nodes = 5;

  // Adjacency list representation of the graph
  vector<vector<int>> adjList(nodes + 1);

  addEdge(adjList, 0, 1);
  addEdge(adjList, 0, 2);
  addEdge(adjList, 0, 4);
  addEdge(adjList, 3, 4);

  // Add edges to the graph
  // addEdge(adjList, 1, 2);
  // addEdge(adjList, 1, 3);
  // addEdge(adjList, 2, 5);
  // addEdge(adjList, 2, 6);
  // addEdge(adjList, 3, 4);
  // addEdge(adjList, 3, 8);
  // addEdge(adjList, 4, 7);
  // addEdge(adjList, 7, 8);

  // bfs_traversal(adjList, nodes, 1);
  // dfs_traversal(adjList, nodes, 1);
  traverse_dfs(adjList, nodes, 1);

  return 0;
}