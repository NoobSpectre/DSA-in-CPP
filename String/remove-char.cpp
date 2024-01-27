/**
 * Given a string, computely recursively a new string where all 'x' chars have been removed.
 * 
 * Input: xaxb
 * 
 * Output: ab
*/

#include<iostream>
#include<string>
using namespace std;

string remove_char(string s, char c) {
  if(s.length() == 0)
    return s;

  if(s[0] == c)
    return remove_char(s.substr(1), c);

  return s[0] + remove_char(s.substr(1), c);
}

int main() {
  string s;
  cin >> s;

  char char_to_remove = 'x';

  cout << "The new string with all x's removed: " << remove_char(s, char_to_remove);

  return 0;
}