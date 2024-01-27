/**
 * Given k, find the geometric sum i.e. 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) using recursion. Return the answer.
 * 
 * Input: 3
 * 
 * Output: 1.875
*/

#include<iostream>
#include<math.h>
using namespace std;

double get_gp_sum(const int first_term, const int common_ratio, int k) {
  return 2 - (1 / pow(2, k));
}

int main() {
  int k;
  cin >> k;

  // gp: 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)

  const int first_term = 1;
  const int common_ratio = 2;

  cout << "The resultant sum of the given gp: " << get_gp_sum(first_term, common_ratio, k);

  return 0;
}