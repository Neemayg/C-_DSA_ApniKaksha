#include <iostream>
using namespace std;

int main() {
    int data[5];
    int i, n;
    int item;
    bool found = false;

    cout << "Enter 5 values for the array:" << endl;
    for (i = 0; i < 5; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> data[i];
    }

    cout << "\nEnter the Element you want to search: ";
    cin >> item;

    for (n = 0; n < 5; n++) {
        if (data[n] == item) {
            cout << "The Index for the following element in array is " << n << endl;
            found = true;
            break;
        }
    }

    if (found == false) {
        cout << "Item not present in the array." << endl;
    }

    return 0;
}
