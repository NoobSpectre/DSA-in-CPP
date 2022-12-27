// Enter a number and return the sum of the odd digits and even digits separately.

#include<iostream>
using namespace std;

int main() {
  cout << "Enter a number: ";
  int n; cin >> n;

  int sum_even = 0, sum_odd = 0;
  do {
    ((n % 10) & 1) ? sum_odd += (n % 10): sum_even += (n % 10);
  } while ((n /= 10) > 0);

  cout << "Even: " << sum_even << " odd: " << sum_odd << endl;

  return 0;
}