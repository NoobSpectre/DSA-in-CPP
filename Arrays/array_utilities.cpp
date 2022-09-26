#include<iostream>
#include<vector>
using namespace std;

void printVec(const vector<int>& args) {
  for(int i: args) {
    cout << i << " ";
  }
  cout << endl;
}