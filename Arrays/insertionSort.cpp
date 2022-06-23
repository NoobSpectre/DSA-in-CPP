#include<iostream>
using namespace std;

void insertionSort(int* &arr, int _size) {
    int i = 1;
    while(i < _size) {
        int temp = arr[i];
        int j=i-1;
        while(j >= 0) {
            if(temp < arr[j]) {
                arr[j+1] = arr[j];
            }
            else break;
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}

int main() {
    cout << "Enter the no. of elements: ";
    int _size; cin >> _size;

    int *arr = NULL;
    arr = new int[_size];
    // int arr[5];
    cout << "Enter the elements: ";
    for(int i=0; i<_size; i++) {
        cin >> arr[i];
    }

    cout << "Before sorting, the array is: ";
    for(int i=0; i<_size; i++) {
        cout << arr[i] << " ";
    }

    insertionSort(arr, _size);

    cout << "\nAfter sorting, the array is: ";
    for(int i=0; i<_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}