#include<iostream>
#include<vector>
#include<ctime>
#include <algorithm>
using namespace std;

// typedef int (*pivot_getter_func)(vector<int>&v);

// int partitionIndex(vector<int>& v, int s, int e, pivot_getter_func getPivotIndex) {
//     // for end exlusive
//     // int end = e + 1;
//     // int mid = s + (end - s) / 2; // int overflow
//     // int pivot = v[mid];
//     srand(time(0));

//     int pivotIndex = getPivotIndex(v);
//         // int pivotIndex = s;
//     for(int i=s; i<=e; i++) {
//         if(v[i] < pivot) pivotIndex++;
//     }

//     swap(v[pivotIndex], v[_rand]);

//     int i = s, j = e;
//     while (i < pivotIndex && j > pivotIndex) {
//         while(v[i] < pivotIndex) {
//             i++;
//         }

//         while(v[j] > pivotIndex) {
//             j--;
//         }

//         if(i < pivotIndex && j > pivotIndex) {
//             swap(v[i], v[j]);
//         }
//     }
    
//     return pivotIndex;
// }

// void quickSort(vector<int>& v, int s, int e) {
//     //base case
//     if(s >= e) return;

//     //return partition index
//     int _partition_index = partitionIndex(v, s, e, [](v) { 
//         int mid = v.size() / 2;
//         return mid;
//     });

//     //quicksort left part of partition index
//     quickSort(v, s, _partition_index - 1);

//     //quicksort right part of partition index
//     quickSort(v, _partition_index + 1, e);
// }

int main() {
    vector<int> vec = {4,5,9,14,11,1};

    // cout << "Before sorting, the list of elements is: ";
    // for(int i: vec) {
    //     cout << i << " ";
    // }
    // cout << '\n';

    // quickSort(vec, 0, vec.size() - 1);

    // cout << "After sorting, the list of elements is: ";
    // for(int i: vec) {
    //     cout << i << " ";
    // }
    // cout << '\n';
    // return 0;
    auto getMax = [](vector<int> &v) {
        return *max_element(v.begin(), v.end());
    };

    cout << getMax(vec) << endl;
}