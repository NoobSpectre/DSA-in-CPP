#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  // for (int i = 65; i < (65 + n); i++) {
  //   char ch = i;
  //   for (int j = 65; j <= i; j++) {
  //     cout << ch++;
  //   }
  //   cout << endl;
  // }

  int i = 65;
  while(i < (65 + n)) {
    char ch = i;
    int j = 65;
    while(j++ <= i) {
      cout << ch++;
    }
    i++;
    cout << endl;
  }

  return 0;
}