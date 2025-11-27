#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves: arr[st..mid] and arr[mid+1..end]
void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    // Merge the two halves
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy leftover from left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy leftover from right half
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted content back into original array
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
}

// Merge Sort function
void mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);       // sort left half
        mergeSort(arr, mid + 1, end);  // sort right half

        merge(arr, st, mid, end);      // merge halves
    }
}

int main() {
    vector<int> arr = {12, 31, 35, 8, 22, 17};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
