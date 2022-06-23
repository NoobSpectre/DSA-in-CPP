// Tree cutting efficiently problem - solved using BInary Search

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &row, int m, int mid) {
    int woodCount = 0;
    for(int i: row) {
        woodCount += ((i > mid) ? (i - mid) : 0);
        if(woodCount >= m) return true;
    } return false;
}

int max_height(vector<int> &row, int m) {
    int s = 0; 
    int e = -1;
    for(int i: row) e = max(e,i);
    int mid = s + (e - s)/2;

    int ans = -1;
    while(s <= e) {
        if (isPossible(row, m, mid)) {
            ans = mid;
            s = mid + 1;
        } else e = mid - 1;
        mid = s + (e - s)/2;
    } return ans;
}

int main() {
    cout << "Enter the no. of testcases: ";
    int t; cin >> t;
    
    while(t--) {
        cout << "Enter the no. of trees: ";
        int n; cin >> n;
        cout << "Enter the amount of wood required: ";
        int m; cin >> m;
        cout << "Enter the heights of the trees: ";
        vector<int> row(0);
        for(int i=0; i<n; i++) {
            int height; cin >> height;
            row.push_back(height);
        }

        cout << "The required maximum integer height of the sawblade is: " << max_height(row, m) << endl;
    }

    return 0;
}