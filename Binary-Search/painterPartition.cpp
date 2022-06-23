// Painter partition problem (same as book allocation problem) - solved using Binary Search //

#include <iostream>
#include <vector>
using namespace std;

// function to check whether it is possible to paint all the boards within mid-amount of minimum time
bool isPossible(vector<int> boards, int k, int mid) {  
    int paintercount = 1;
    int units_of_boards = 0;

    for(int i: boards) {
        if(units_of_boards + i <= mid)
            units_of_boards += i;
        else {
            paintercount++;
            if(paintercount > k || i > mid) return false;
            units_of_boards = i;
        }
    }

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int s = 0;
    int e = 0;
    for(int i: boards)
        e += i;
    int mid = s + (e - s) / 2;

    int ans = -1;
    while (s <= e) {
        if(isPossible(boards, k, mid)) {
            ans = mid;        // if a possible solution, then ans = mid(possiblle solution)
            e = mid - 1;      // if a possible solution, then right part of mid is discarded and end becomes (mid-1)
        } else { 
            s = mid + 1;      // if not a possible solution, then left part of mid is discarded and s becomes (mid+1)
        }
        mid = s + (e - s) / 2;
    }
    
    return ans;
}

int main() {
    cout << "Enter the no. of testcases: ";
    int t; cin >> t;

    while(t--) {
        cout << "Enter the no. of boards: ";
        int n; cin >> n;
        cout << "Enter the no. of painters: ";
        int k; cin >> k;
        cout << "Enter the units of boards: ";
        vector<int> boards;
        for(int i=0; i<n; i++) {
            int ele; cin >> ele;
            boards.push_back(ele);
        }

        cout << "The required minimum time is: " << findLargestMinDistance(boards, k) << endl;
    }

    return 0;
}

