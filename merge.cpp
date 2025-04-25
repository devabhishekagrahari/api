#include <iostream>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m) {
    int i = 0;
    int j = 1;

    cout << "Initial sizes => arr1 (n): " << n << ", arr2 (m): " << m << endl;
    cout << "Initial arr1: ";
    for (int k = 0; k < n; k++) cout << arr1[k] << " ";
    cout << "\nInitial arr2: ";
    for (int k = 0; k < m; k++) cout << arr2[k] << " ";
    cout << "\n\n";

    // First loop: compare and swap if arr1[i] > arr2[0]
    while (i < n) {
        cout << "[Merge Phase 1] Comparing arr1[" << i << "] = " << arr1[i]
             << " with arr2[0] = " << arr2[0] << endl;

        if (arr1[i] > arr2[0]) {
            cout << " -> Swapping arr1[" << i << "] and arr2[0]" << endl;
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;
        }
        i++;
    }

    cout << "\nAfter Phase 1 arr1: ";
    for (int k = 0; k < n; k++) cout << arr1[k] << " ";
    cout << "\nAfter Phase 1 arr2: ";
    for (int k = 0; k < m; k++) cout << arr2[k] << " ";
    cout << "\n\n";

    // Second loop: bubble the new swapped element in arr2 to the correct position
    while (j < m) {
        cout << "[Merge Phase 2] Comparing arr2[" << j - 1 << "] = " << arr2[j - 1]
             << " with arr2[" << j << "] = " << arr2[j] << endl;

        if (arr2[j] < arr2[j - 1]) {
            cout << " -> Swapping arr2[" << j - 1 << "] and arr2[" << j << "]" << endl;
            int temp = arr2[j];
            arr2[j] = arr2[j - 1];
            arr2[j - 1] = temp;
        }
        j++;
    }

    cout << "\nAfter Phase 2 Final arr1: ";
    for (int k = 0; k < n; k++) cout << arr1[k] << " ";
    cout << "\nAfter Phase 2 Final arr2: ";
    for (int k = 0; k < m; k++) cout << arr2[k] << " ";
    cout << "\n";
}

int main() {
    int arr1[] = {0,1,10};
    int arr2[] = {1,1,4};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    merge(arr1, n, arr2, m);

    cout << "\n=== Final Merged Output ===\n";
    cout << "arr1: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2: ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
