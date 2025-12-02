#include <iostream>
using namespace std;

void merge(int arr[], int st, int mid, int end);

void mergesort(int arr[], int st, int end) {
    if(st < end) {
        int mid = st + (end - st) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

void merge(int arr[], int st, int mid, int end) {
    int temp[end - st + 1];
    int i = st, j = mid + 1, k = 0;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= end) temp[k++] = arr[j++];

    for(int idx = 0; idx < k; idx++) {
        arr[st + idx] = temp[idx];
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
