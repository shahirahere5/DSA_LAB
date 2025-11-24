#include <iostream>
using namespace std;

void shellSort(int myarr[],int n1){
    for(int gap = n1/2 ; gap > 0 ; gap /= 2){
        for(int j=gap ; j<n1; j++){
            int temp = myarr[j];
            int res = j;

            while( res >= gap && myarr[res - gap]> temp){
                myarr[res] = myarr[res-gap];
                res -= gap;
            }
            myarr[res] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Sorted Array (Shell Sort): ";
    printArray(arr, n);

    return 0;
}