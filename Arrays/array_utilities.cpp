#include<iostream>
#include<vector>
using namespace std;

void printVec(const vector<int>& args) {
  for(int i: args) {
    cout << i << " ";
  }
  cout << endl;
}

void print_matrix(vector<vector<int>>& matrix) {
  for(int i=0; i<matrix.size(); i++) {
    for(int j=0; j<matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}