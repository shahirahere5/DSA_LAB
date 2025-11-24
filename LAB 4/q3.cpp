#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int bubbleSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    return comparisons;
}

int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int selectionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    return comparisons;
}

int shellSort(int arr[], int n) {
    int comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                comparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
    return comparisons;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = source[i];
}

int main() {
    srand(time(0));

    int n1 = 20, n2 = 100;

    cout << "Sorting 20 Random Integers" << endl;
    int arr20[20], temp[20];

    for (int i = 0; i < n1; i++)
        arr20[i] = rand() % 100 + 1;

    cout << "Original Array (20): ";
    printArray(arr20, n1);

    copyArray(arr20, temp, n1);
    int compBubble = bubbleSort(temp, n1);
    cout << "\nBubble Sort Result: ";
    printArray(temp, n1);
    cout << "Comparisons: " << compBubble << endl;

    copyArray(arr20, temp, n1);
    int compInsertion = insertionSort(temp, n1);
    cout << "\nInsertion Sort Result: ";
    printArray(temp, n1);
    cout << "Comparisons: " << compInsertion << endl;

    copyArray(arr20, temp, n1);
    int compSelection = selectionSort(temp, n1);
    cout << "\nSelection Sort Result: ";
    printArray(temp, n1);
    cout << "Comparisons: " << compSelection << endl;

    copyArray(arr20, temp, n1);
    int compShell = shellSort(temp, n1);
    cout << "\nShell Sort Result: ";
    printArray(temp, n1);
    cout << "Comparisons: " << compShell << endl;

    cout << "\nSorting 100 Random Integers" << endl;
    int arr100[100], temp2[100];

    for (int i = 0; i < n2; i++)
        arr100[i] = rand() % 100 + 1;

    cout << "Original Array (100): ";
    printArray(arr100, n2);

    copyArray(arr100, temp2, n2);
    compBubble = bubbleSort(temp2, n2);
    cout << "\nBubble Sort Result: ";
    printArray(temp2, n2);
    cout << "Comparisons: " << compBubble << endl;

    copyArray(arr100, temp2, n2);
    compInsertion = insertionSort(temp2, n2);
    cout << "\nInsertion Sort Result: ";
    printArray(temp2, n2);
    cout << "Comparisons: " << compInsertion << endl;

    copyArray(arr100, temp2, n2);
    compSelection = selectionSort(temp2, n2);
    cout << "\nSelection Sort Result: ";
    printArray(temp2, n2);
    cout << "Comparisons: " << compSelection << endl;

    copyArray(arr100, temp2, n2);
    compShell = shellSort(temp2, n2);
    cout << "\nShell Sort Result: ";
    printArray(temp2, n2);
    cout << "Comparisons: " << compShell << endl;

    return 0;
}
