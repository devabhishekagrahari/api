#include <iostream>
using namespace std;

void rotate90(int arr[][4], int n, int m) {
    int Vrange = n;
    int Hrange = m;
    int low = 0, high = 0;
    int turn = m;
    int key = arr[0][0];
    int rotate = n;  // This tracks the layers to rotate

    // Outer loop that processes the layers
    while (turn > 0) {
        // Rotate layer-by-layer
        while (rotate > 0) {
            // Rotate each side of the layer one by one

            // Move elements from left to top
            while (low < Vrange) {
                arr[low][high] = arr[low + 1][high];
                low++;
            }

            // Move elements from top to right
            while (high < Hrange) {
                arr[low][high] = arr[low][high + 1];
                high++;
            }

            // Move elements from right to bottom
            while (low > 0) {
                arr[low][high] = arr[low - 1][high];
                low--;
            }

            // Move elements from bottom to left
            while (high > ) {
                arr[low][high] = arr[low][high - 1];
                high--;
            }

            // Place the original key at its new position
            arr[low][high] = key;

            // Update the ranges and indices
            Vrange--;
            Hrange--;
            low--;
            high++;

            // Decrease the rotation count for the current layer
            rotate--;
        }

        // Decrease turns for the outer loop and prepare for the next layer
        turn--;
    }
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotate90(arr, 4, 4);

    // Print the rotated matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
