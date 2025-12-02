#include <iostream>
using namespace std;

void combSort(int arr[], int n) {
    double shrink = 1.3;
    int gap = n;
    bool swapped = true;

    while(gap > 1 || swapped) {
        gap = int(gap / shrink);
        if(gap < 1) gap = 1;
        swapped = false;
        for(int i = 0; i + gap < n; i++) {
            if(arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}

int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    combSort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
