#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> keypad = {
                              {1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9},
                              {-1, 0, -1}
                            };

int solve(int posY, int posX, int n) {
  //Non-existant positions
  if(posX < 0 || posY < 0 || posX > 2 || posY > 3) return 0;

  //'*' and '#' are excluded
  if((posX == 0 && posY == 3) || (posX == 2  && posY == 3)) return 0;

  //base case
  if(n == 1) return 1;

  //up, left, right and down positions of the current position
  int upCombinations = solve(posY - 1, posX, n - 1);
  int leftCombinations = solve(posY, posX - 1, n - 1);
  int rightCombinations = solve(posY, posX + 1, n - 1);
  int downCombinations = solve(posY + 1, posX, n - 1);

  return upCombinations + leftCombinations + rightCombinations + downCombinations + 1;
}

int numberofCcombinations(int n) {
  if(n <= 0) return 0;

  int ans = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if(keypad[i][j] == -1) continue;
      ans += solve(i, j, n);
    }
  }

  return ans;
}

int main() {
  cout << "Enter the value of N: ";
  int n; cin >> n;

  cout << "\nThe number of combinations is : " << numberofCcombinations(n) << endl;

  return 0;
}