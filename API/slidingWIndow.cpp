#include <iostream>
#include <cstdio>
using namespace std;

int windowMaxsum(int arr[], int k, int n) {
    int windowMax = 0;

    // First window sum
    cout << "Initial window: ";
    for (int i = 0; i < k; i++) {
        windowMax += arr[i];
        cout << arr[i] << " ";
    }
    cout << "=> Sum = " << windowMax << endl;

    int currentSum = windowMax;

    // Slide the window
    for (int i = k; i < n; i++) {
        currentSum = currentSum - arr[i - k] + arr[i];
        cout << "Window moved: Remove " << arr[i - k] << ", Add " << arr[i] 
             << " => New sum = " << currentSum << endl;
        windowMax = max(windowMax, currentSum);
    }

    return windowMax;
}

int main() {
    int arr[] = {5, 6, 7, 1, 2, 3, 4};
    int k = 3;
    int result = windowMaxsum(arr, k, sizeof(arr) / sizeof(arr[0]));
    cout << "\n🔺 Maximum sum of subarray of size " << k << " is: " << result << endl;
    return 0;
}
