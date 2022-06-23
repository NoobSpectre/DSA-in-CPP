/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

Example-1:
  Input: digits = "23"
  Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example-2:
  Input: digits = ""
  Output: []

Example-3:
  Input: digits = "2"
  Output: ["a", "b", "c"]

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string digits, int index, string& output, vector<string> &ans, vector<string>& mapping) {
  //base case
  if(index >= digits.length()) {
    ans.push_back(output);
    return;
  }

  int num = digits[index] - '0';
  string val = mapping[num];

  for (int i = 0; i < val.length(); i++) {
    output.push_back(val[i]);
    solve(digits, index + 1, output, ans, mapping);
    output.pop_back();
  }
}

vector<string> ph_numCombinations(string digits) {
  vector<string> ans;

  if(digits.length() <=0)
    return ans;

  vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  int index = 0;
  string output = "";

  solve(digits, index, output, ans, mapping);

  return ans;
}

int main() {
  cout << "Enter the phone number: ";
  string ph_num; cin >> ph_num;

  cout << "The all possible combinations of the given phone number: \n";
  vector<string> combinations = ph_numCombinations(ph_num);
  cout << "[";
  for(auto i: combinations) {
    cout << "\"" << i << "\"";
  }
  cout << "]";

  return 0;
}