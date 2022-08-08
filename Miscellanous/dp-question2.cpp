#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void print(const vector<int>& args) {
  cout << "Sequence is: ";
  for(int i: args) {
    cout << i << " ";
  }
  cout << endl;
}

vector<int> largestSortedSequence(vector<int> &arr) { // [2, 7, 1, 3, 6, 5, 4], [2, 1, 3, 4, 5]
  vector<int> ans;
  if(arr.size() == 0) return ans;

  vector<int> sequence;
  int prev = INT_MIN;

  for (int i = 0; i < arr.size(); i++) {
    if(prev > arr[i]) {
      if(sequence.size() > ans.size()) {
        ans = sequence;
      }
      sequence.clear();
    }
    sequence.push_back(arr[i]);
    prev = arr[i];
  }

  if(sequence.size() > ans.size()) return sequence;

  return ans;
}

int main() {
  cout << "Enter the no. of elements: ";
  int n; cin >> n;

  vector<int> vec(n);
  
  if(n > 0) {
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
  }

  vector<int> result = largestSortedSequence(vec);

  cout << "The largest sorted sequence is: ";
  for(int i: result) {
    cout << i << " ";
  }

  return 0;
}