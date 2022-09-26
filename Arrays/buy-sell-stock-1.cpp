#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices) {
  if(prices.size() == 1) return 0;
  
  int left = 0, right = 1;
  int n = prices.size();
  
  int profit = INT_MIN;
  while(right < n) {
    if(prices[right] < prices[left]) {
      left = right;
    } else {
      profit = max(profit, (prices[right] - prices[left]));
    }
    
    right++;
  }
  
  if(profit > 0) return profit;
  return 0;
}

int main() {
  cout << "Enter the number of stocks: ";
  int n; cin >> n;

  cout << "Enter the stocks' prices: ";
  vector<int> stocks(n);
  for(int i = 0; i < n; i++) {
    cin >> stocks[i];
  }

  cout << "The maximum profit is: " << maxProfit(stocks) << endl;

  return 0;
}