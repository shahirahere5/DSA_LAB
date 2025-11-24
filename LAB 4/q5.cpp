#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j= i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int myArr[] = {9,5,1,4,3,14,119};
    int n= sizeof(myArr) / sizeof(myArr[0]);
    cout << "Original Array: ";
    printArray(myArr, n);
    insertionSort(myArr, n);
    cout << "Sorted Array (Insertion Sort): ";
    printArray(myArr, n);
    return 0;
}