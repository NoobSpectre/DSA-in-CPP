#include<iostream>
using namespace std;

int partitionIndex(int* &arr, int s, int e) {
    int pivot = arr[s];
    int pivotIndex = s;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivot)
            pivotIndex++;
    }

    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(int* &arr, int s, int e) {
    //base case
    if(s >= e) return;

    int _partition_Index = partitionIndex(arr, s, e);

    //sorting left part of pivot
    quickSort(arr, s, _partition_Index-1);

    //sorting right part of pivot
    quickSort(arr, _partition_Index+1, e);
}

int main() {
    cout << "Enter the no. of elements: ";
    int _size; cin >> _size;

    int *arr = NULL;
    arr = new int[_size];
    cout << "Enter the elements: ";
    for(int i=0; i<_size; i++) {
        cin >> arr[i];
    }

    cout << "Before sorting, the array is: ";
    for(int i=0; i<_size; i++) {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, _size-1);

    cout << "\nAfter sorting, the array is: ";
    for(int i=0; i<_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}