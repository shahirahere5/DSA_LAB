#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; 
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target = 5;
    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Value " << target << " found at index " << result << endl;
    else
        cout << "Value not found" << endl;

    return 0;
}
