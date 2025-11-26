#include <iostream>
using namespace std;

int main() {
    int arr[100], i, n, item, beg, end, mid;

    cout << "Enter the number of elements you want to enter: ";
    cin >> n;

    cout << "Enter the elements in sorted manner: " << endl;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element you want to search: ";
    cin >> item;

    beg = 0;
    end = n - 1;
    bool found = false;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (arr[mid] == item) {
            cout << "Element is at index: " << mid << endl;
            found = true;
            break;
        }
        else if (item < arr[mid]) {
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }
    }

    if (!found) {
        cout << "Element is not present in the array." << endl;
    }

    return 0;
}
