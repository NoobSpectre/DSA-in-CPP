/**
 * Given a string, remove consecutive duplicates from it recursively.
 * 
 * Input: aabccba
 * 
 * Output: abcba
*/

#include<iostream>
#include<string>
using namespace std;

string remove_consecutive_duplicates(string s) {
  if(s.length() <= 1)
    return s;

  if(s[0] == s[1])
    return "" + remove_consecutive_duplicates(s.substr(1));

  return s[0] + remove_consecutive_duplicates(s.substr(1));
}

int main() {
  string s;
  cin >> s;

  cout << "After consecutive duplicates removal, the new string is: " << remove_consecutive_duplicates(s);

  return 0;
}