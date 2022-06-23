#include<iostream>
#include<vector>
using namespace std;

int begIndex(vector<int> &v, int n, int target) {
    int s = 0;
    int e = n - 1;
    int mid = s + ((e - s) / 2);
    int ans = -1;

    while(s <= e) {
        if(v[mid] == target) {
            ans = mid;
            e = mid - 1;
        }
        else if(v[mid] < target) s = mid + 1;
        else e = mid - 1;

        mid = s + ((e - s) / 2);
    }

    return ans;
}

int endIndex(vector<int> &v, int n, int target) {
    int s = 0;
    int e = n - 1;
    int mid = s + ((e - s) / 2);
    int ans = -1;

    while(s <= e) {
        if(v[mid] == target) {
            ans = mid;
            s = mid + 1;
        }
        else if(v[mid] < target) s = mid + 1;
        else e = mid - 1;

        mid = s + ((e - s) / 2);
    }

    return ans;
}

int frequency(vector<int> &v, int n, int target) {
    int beg, end;
    beg = begIndex(v, n, target);
    end = endIndex(v, n, target);
    if(beg == -1 && end == -1) return 0;
    return (end - beg + 1);
}

int main() {
    cout << "Enter the number of integers: ";
    int n; cin >> n;

    cout << "Enter the sorted array: ";
    vector<int> v;
    for(int i=0; i<n; i++) {
        int ele; cin >> ele;
        v.push_back(ele);
    }

    cout << "Enter the number of testcases: ";
    int testcases; cin >> testcases;

    while(testcases--) {
        cout << "Enter the target value: ";
        int target; cin >>target;

        cout << "Frequency of the target value is: " << frequency(v, n, target) << endl;
    }
    return 0;
}