/**
 * Given an integer n, count and return the number of zeros that are present in the given integer using recursion.
 * 
 * Input: 10204
 * 
 * Output: 2
 */

#include<iostream>
using namespace std;

int get_zeros_from(int n) {
  if(n < 10)
    return 0;

  return n % 10 ? get_zeros_from(n / 10) : 1 + get_zeros_from(n / 10);
}

int main() {
  int n;
  cin >> n;

  cout << "The number of zeros in the given integer: " << get_zeros_from(n);

  return 0;
}