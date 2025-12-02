#include <iostream>
using namespace std;

int main() {
    // 1D Array
    int arr1D[] = {1, 2, 3, 4, 5};
    int n1D = sizeof(arr1D)/sizeof(arr1D[0]);
    cout << "1D Array: ";
    for(int i = 0; i < n1D; i++) cout << arr1D[i] << " ";
    cout << endl << "-------------" << endl;

    // 2D Array
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "2D Array:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) cout << arr2D[i][j] << " ";
        cout << endl;
    }
    cout << "-------------" << endl;

    // Jagged Array
    int* jagged[3];
    int sizes[3] = {2, 3, 4};
    for(int i = 0; i < 3; i++) {
        jagged[i] = new int[sizes[i]];
        for(int j = 0; j < sizes[i]; j++)
            jagged[i][j] = (i+1)*(j+1);
    }
    cout << "Jagged Array:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < sizes[i]; j++)
            cout << jagged[i][j] << " ";
        cout << endl;
    }

    for(int i = 0; i < 3; i++) delete[] jagged[i];
}
