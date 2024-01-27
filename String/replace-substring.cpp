/**
 * Given a string, computely recursively a new string where all appearances of 'pi' have been replaced by "3.14".
 * 
 * Input: xpix
 * 
 * Output: x3.14x
*/

#include<iostream>
#include<string>
using namespace std;

string replace_substr(string s,const string sub, const int sub_len, const string value) {
  if(s.length() == 0)
    return s;

  if(s.substr(0, sub_len) == sub)
    return "3.14" + replace_substr(s.substr(sub_len), sub, sub_len, value);

  return s[0] + replace_substr(s.substr(1), sub, sub_len, value);
}

int main() {
  string s;
  cin >> s;

  const string substr_to_replace = "pi";
  const string value_to_replace_with = "3.14";
  const int substr_to_replace_len = substr_to_replace.length();

  cout << "The new string with all x's removed: " << replace_substr(s, substr_to_replace, substr_to_replace_len, value_to_replace_with);

  return 0;
}