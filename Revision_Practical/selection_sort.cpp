#include<iostream>
using namespace std;

int main() {
    int arr[100], n, i, j, temp;

    cout << "Enter no of elements you want to enter: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort Logic
    for (i = 0; i < n - 1; i++) {
        int minimum_val = i;   // index of smallest element

        // find the smallest element in remaining array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minimum_val]) {
                minimum_val = j;
            }
        }

        // swap arr[i] with arr[minimum_val]
        if (minimum_val != i) {
            temp = arr[i];
            arr[i] = arr[minimum_val];
            arr[minimum_val] = temp;
        }
    }

    cout << "Sorted array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
